#include <curl/curl.h>

#include <cstring>
#include <format>
#include <libcurl/curl.hxx>
#include <utility>

namespace libcurl {
/**
 * @brief Left strip string
 *
 * @param str The string to strip
 * @return The left stripped string
 */
[[nodiscard]] auto lstrip(std::string_view str) noexcept -> std::string {
    return {std::find_if(str.cbegin(), str.cend(),
                         [](auto ch) { return !std::isspace(ch); })};
}

/**
 * @brief Right strip string
 *
 * @param str The string to strip
 * @return The right stripped string
 */
[[nodiscard]] auto rstrip(std::string_view str) noexcept -> std::string {
    return {str.begin(), std::find_if(str.crbegin(), str.crend(), [](auto ch) {
                             return !std::isspace(ch);
                         }).base()};
}

/**
 * @brief Left and right strip string
 *
 * @param str The string to strip
 * @return The left and right stripped string
 */
[[nodiscard]] auto strip(std::string_view str) noexcept -> std::string {
    return lstrip(rstrip(str));
}

/**
 * @brief Cleanup wrapper for CURL struct
 *
 * @param curl The CURL struct to cleanup
 */
auto cleanup(CURL* curl) noexcept -> void {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

/**
 * @brief Represents the memory buffer for the response body
 */
struct mem_buffer {
    char* data {(char*)malloc(1)};
    size_t size {};
};

/**
 * @brief Write the response body chunk to the memory buffer
 *
 * @param contents The contents to write
 * @param size The size each item in the chunk
 * @param nitems The number of items in the chunk
 * @param userp The memory buffer to write
 * @return The size written
 */
auto writeBodyCallback(void* contents, std::size_t size, std::size_t nitems,
                       void* userp) -> std::size_t {
    const auto realsize {size * nitems};

    auto* mem {(mem_buffer*)userp};
    auto* ptr {(char*)realloc(mem->data, mem->size + realsize + 1)};

    // check for out of memory
    if (!ptr) return 0;

    mem->data = ptr;
    std::memcpy(&(mem->data[mem->size]), contents, realsize);
    mem->size += realsize;

    // NULL terminated string
    mem->data[mem->size] = 0;

    return realsize;
}

/**
 * @brief Write the response headers chunk to the memory buffer
 *
 * @param buffer The header line (<name>: <value>)
 * @param size The size each item in the chunk
 * @param nitems The number of items in the chunk
 * @param headers The memory buffer to write to
 * @return The size written
 */
auto writeHeaderCallback(char* buffer, size_t size, size_t nitems,
                         std::unordered_map<std::string, std::string>* headers)
    -> std::size_t {
    const auto realSize {size * nitems};

    const auto header {strip({buffer, realSize})};

    // skip end marker
    if (header.empty()) return realSize;

    const auto pos {header.find(": ")};

    // skip protocol, version and status
    if (pos == std::string::npos) return realSize;

    const auto it {header.begin() + pos};

    const std::string name {header.begin(), it};
    const std::string val {it + 2, header.end()};
    (*headers)[name] = val;

    return realSize;
}

/**
 * @brief Compose the url appending each parameter after escaping
 *
 * @param req The request
 * @param curl The initialized CURL object
 * @return The composed url
 */
[[nodiscard]] auto composeUrl(const request& req, CURL* curl) -> std::string {
    std::string composedUrl {req.getUrl()};

    const auto params {req.getParameters()};
    if (params.size() != 0) {
        composedUrl += "?";
        for (const auto& [k, v] : params) {
            auto* buffer {curl_easy_escape(curl, k.c_str(), k.size())};

            if (!buffer) {
                curl_free(buffer);
                cleanup(curl);
                throw std::runtime_error(
                    std::format("Cannot escape parameter name: {:?}", k));
            }

            composedUrl += std::string {buffer} + "=";

            buffer = curl_easy_escape(curl, v.c_str(), v.size());

            if (!buffer) {
                curl_free(buffer);
                cleanup(curl);
                throw std::runtime_error(
                    std::format("Cannot escape parameter value: {:?}", v));
            }

            composedUrl += std::string {buffer} + "&";

            curl_free(buffer);
        }

        composedUrl.pop_back(); // remove leading &
    }

    return composedUrl;
}

/**
 * @brief Compose the post fields list appending each post field after escaping
 *
 * @param req The request
 * @param curl The initialized CURL object
 * @return The composed post fields
 */
[[nodiscard]] auto composePostFields(const auto& req, CURL* curl)
    -> std::string {
    std::string composedPostFields {};

    const auto postFields {req.getPostFields()};

    // check for json content
    if (req.getHeader(headers::CONTENT_TYPE) == "application/json"
        && postFields.size() != 0) {
        cleanup(curl);
        throw std::runtime_error(
            std::format("Only one post field is expected when header "
                        "'{}' is 'application/json'",
                        getHeaderName(headers::CONTENT_TYPE)));
    }

    if (postFields.size() != 0) {
        for (const auto& [k, v] : postFields) {
            auto* buffer {curl_easy_escape(curl, k.c_str(), k.size())};

            if (!buffer) {
                curl_free(buffer);
                cleanup(curl);
                throw std::runtime_error(
                    std::format("Cannot escape post field name: {:?}", k));
            }

            composedPostFields += std::string {buffer} + "=";

            buffer = curl_easy_escape(curl, v.c_str(), v.size());

            if (!buffer) {
                curl_free(buffer);
                cleanup(curl);
                throw std::runtime_error(
                    std::format("Cannot escape post field value: {:?}", v));
            }

            composedPostFields += std::string {buffer} + "&";

            curl_free(buffer);
        }

        composedPostFields.pop_back(); // remove leading &
    }

    return composedPostFields;
}

/**
 * @brief Compose the headers collection
 *
 * @param req The request
 * @return The composed headers in curl_slist*
 */
[[nodiscard]] auto composeHeaders(const auto& req) -> curl_slist* {
    const auto headers {req.getHeaders()};

    curl_slist* composedHeaders {NULL};
    for (const auto& [k, v] : headers)
        composedHeaders = curl_slist_append(composedHeaders, std::string {k + ": " + v}.c_str());

    return composedHeaders;
}

auto curl(request req) -> std::future<response> {
    return std::async(
        [](request req) -> response {
            curl_global_init(CURL_GLOBAL_ALL);
            auto* curl {curl_easy_init()};

            if (!curl) {
                cleanup(curl);
                throw std::runtime_error("Cannot initialize curl");
            }

            // request url setup
            const auto composedUrl {composeUrl(req, curl)};
            curl_easy_setopt(curl, CURLOPT_URL, composedUrl.c_str());

            switch (req.getMethod()) {
                case methods::GET:
                    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
                case methods::HEAD:
                default:
                    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST,
                                     getMethodName(req.getMethod()).c_str());
            }

            // request headers setup
            auto composedHeaders {composeHeaders(req)};
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, composedHeaders);

            // request post fields setup
            const auto composedPostFields {composePostFields(req, curl)};
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS,
                             composedPostFields.c_str());

            // response headers setup
            std::unordered_map<std::string, std::string> headers {};
            curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, writeHeaderCallback);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &headers);

            // response body setup
            mem_buffer body {};
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeBodyCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&body);

            const auto curlCode {curl_easy_perform(curl)};

            if (curlCode != CURLE_OK) {
                cleanup(curl);
                curl_slist_free_all(composedHeaders);
                throw std::runtime_error(
                    std::format("Request failed: CURL code was {}",
                                std::to_underlying(curlCode)));
            }

            // set response status code
            long statusCode {};
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);

            response res {composedUrl, (status_codes)statusCode, {}, body.data};

            // set response headers
            for (const auto& [k, v] : headers) res.setHeader(k, v);

            cleanup(curl);
            free(body.data);
            curl_slist_free_all(composedHeaders);

            return res;
        },
        req);
}
} // namespace libcurl
