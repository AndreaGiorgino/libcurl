#include <curl/curl.h>

#include <cstring>
#include <format>
#include <libcurl/curl.hxx>

namespace libcurl {
[[nodiscard]] auto lstrip(std::string_view str) noexcept -> std::string {
    return {std::find_if(
        str.cbegin(), str.cend(), [](auto ch) { return !std::isspace(ch); })};
}

[[nodiscard]] auto rstrip(std::string_view str) noexcept -> std::string {
    return {str.begin(), std::find_if(str.crbegin(), str.crend(), [](auto ch) {
                return !std::isspace(ch);
            }).base()};
}

[[nodiscard]] auto strip(std::string_view str) noexcept -> std::string {
    return lstrip(rstrip(str));
}

struct mem_buffer {
    char* data {(char*)malloc(1)};
    size_t size {};
};

auto writeBodyCallback(void* contents, std::size_t size, std::size_t nmemb,
    void* userp) -> std::size_t {
    const auto realsize {size * nmemb};

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

auto writeHeaderCallback(char* buffer, size_t size, size_t nitems,
    std::unordered_map<std::string, std::string>* headers) -> std::size_t {
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

auto get(request req) -> std::future<response> {
    return std::async(
        [](request req) -> response {
            auto* curl {curl_easy_init()};

            if (!curl) throw std::runtime_error("Cannot initialize curl");

            curl_easy_setopt(curl, CURLOPT_URL, req.getUrl().c_str());

            switch (req.getMethod()) {
                case methods::GET:
                    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
                    break;
                case methods::HEAD:
                    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST,
                        getMethodName(req.getMethod()).c_str());
                    break;
                default:
                    throw std::runtime_error(
                        std::format("{:?} is not a GET method",
                            getMethodName(req.getMethod())));
            }

            // response headers setup
            std::unordered_map<std::string, std::string> headers {};
            curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, writeHeaderCallback);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &headers);

            // response body setup
            mem_buffer body {};
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeBodyCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&body);

            if (curl_easy_perform(curl) != CURLE_OK)
                throw std::runtime_error("Request failed");

            long statusCode {};
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, statusCode);

            response res {(status_codes)statusCode, {}, body.data};

            for (const auto& [k, v] : headers) res.setHeader(k, v);

            free(body.data);
            curl_easy_cleanup(curl);

            return res;
        },
        req);
}
} // namespace libcurl
