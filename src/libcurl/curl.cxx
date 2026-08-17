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
} // namespace libcurl
