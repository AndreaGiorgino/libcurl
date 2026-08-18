#include <libcurl/response.hxx>

namespace libcurl {
response::response(
    std::string_view url, status_codes statusCode,
    std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
        headers,
    std::string_view body) noexcept
    : _url(url),
      _statusCode(statusCode),
      _body(body) {
    setHeaders(headers);
}

response::response(response&& rhs) noexcept {
    _url        = std::move(rhs._url);
    _statusCode = std::move(rhs._statusCode);
    _headers    = std::move(rhs._headers);
    _body       = std::move(rhs._body);
}

auto response::operator =(response&& rhs) noexcept -> response& {
    _url        = std::move(rhs._url);
    _statusCode = std::move(rhs._statusCode);
    _headers    = std::move(rhs._headers);
    _body       = std::move(rhs._body);

    return *this;
}

auto response::getUrl(void) const noexcept -> std::string {
    return _url;
}

auto response::getStatusCode(void) const noexcept -> status_codes {
    return _statusCode;
}

auto response::getHeader(std::variant<headers, std::string_view> header)
    const noexcept -> std::string {
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

auto response::getBody(void) const noexcept -> std::string {
    return _body;
}

auto response::setUrl(std::string_view url) noexcept -> void {
    _url = url;
}

auto response::setStatusCode(status_codes statusCode) noexcept -> void {
    _statusCode = statusCode;
}

auto response::setHeader(std::variant<headers, std::string_view> header,
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

auto response::setHeaders(
    std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
        headers) noexcept -> void {
    for (const auto& [header, value] : headers) setHeader(header, value);
}

auto response::setBody(std::string_view body) noexcept -> void {
    _body = body;
}
} // namespace libcurl
