#include <libcurl/response.hxx>

namespace libcurl {
auto response::getStatusCode(void) const noexcept -> status_codes {
    return _statusCode;
}

auto response::getHeader(
    std::variant<headers, std::string_view> header) const noexcept
    -> std::string {
    const auto name {std::visit(
        [](const auto& header) -> std::string {
            using clean_t = std::remove_cvref_t<decltype(header)>;

            if constexpr (std::same_as<clean_t, headers>)
                return getHeaderName(header);
            else
                return header.data();
        },
        header)};

    if (const auto it {_headers.find(name)}; it != _headers.end())
        return it->second;
    return {};
}

auto response::getHeaders(void) const noexcept
    -> std::unordered_map<std::string, std::string> {
    return _headers;
}
} // namespace libcurl
