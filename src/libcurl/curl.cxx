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

} // namespace libcurl
