#include <libcurl/request.hxx>

namespace libcurl {
request::request(std::string_view url, methods method,
    std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
        headers) noexcept
    : _url(url),
      _method(method) {
    setHeaders(headers);
}

auto request::getUrl(void) const noexcept -> std::string {
    return _url;
}

auto request::getMethod(void) const noexcept -> methods {
    return _method;
}

auto request::getHeader(
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

auto request::getHeaders(void) const noexcept
    -> std::unordered_map<std::string, std::string> {
    return _headers;
}

auto request::setUrl(std::string_view url) noexcept -> void {
    _url = url;
}

auto request::setMethod(methods method) noexcept -> void {
    _method = method;
}

auto request::setHeader(std::variant<headers, std::string_view> header,
    std::string_view value) noexcept -> void {
    const auto name {std::visit(
        [](const auto& header) -> std::string {
            using clean_t = std::remove_cvref_t<decltype(header)>;

            if constexpr (std::same_as<clean_t, headers>)
                return getHeaderName(header);
            else
                return header.data();
        },
        header)};

    _headers[name] = value;
}

auto request::setHeaders(std::initializer_list<
    std::pair<std::variant<headers, std::string_view>, std::string_view>>
        headers) noexcept -> void {
    for (const auto& [header, value] : headers) setHeader(header, value);
}
} // namespace libcurl
