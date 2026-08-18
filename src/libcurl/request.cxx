#include <libcurl/request.hxx>

namespace libcurl {
request::request(
    std::string_view url, methods method,
    std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
        headers,
    std::initializer_list<std::pair<std::string_view, std::string_view>> params,
    std::initializer_list<std::pair<std::string_view, std::string_view>>
        fields) noexcept
    : _url(url),
      _method(method) {
    setHeaders(headers);
    setParameters(params);
    setPostFields(fields);
}

request::request(request&& rhs) noexcept {
    _url        = std::move(rhs._url);
    _method     = std::move(rhs._method);
    _headers    = std::move(rhs._headers);
    _params     = std::move(rhs._params);
    _postFields = std::move(rhs._postFields);
}

auto request::operator =(request&& rhs) noexcept -> request& {
    _url        = std::move(rhs._url);
    _method     = std::move(rhs._method);
    _headers    = std::move(rhs._headers);
    _params     = std::move(rhs._params);
    _postFields = std::move(rhs._postFields);

    return *this;
}

auto request::getUrl(void) const noexcept -> std::string {
    return _url;
}

auto request::getMethod(void) const noexcept -> methods {
    return _method;
}

auto request::getHeader(std::variant<headers, std::string_view> header)
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

auto request::getHeaders(void) const noexcept
    -> std::unordered_map<std::string, std::string> {
    return _headers;
}

auto request::getParameter(std::string_view param) const noexcept
    -> std::string {
    const std::string name {param};
    if (const auto it {_params.find(name)}; it != _headers.end())
        return it->second;
    return {};
}

auto request::getParameters(void) const noexcept
    -> std::unordered_map<std::string, std::string> {
    return _params;
}

auto request::getPostField(std::string_view field) const noexcept
    -> std::string {
    if (const auto it {_postFields.find(std::string {field})};
        it != _postFields.end())
        return it->second;
    return {};
}

auto request::getPostFields(void) const noexcept
    -> std::unordered_map<std::string, std::string> {
    return _postFields;
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

auto request::setHeaders(
    std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
        headers) noexcept -> void {
    for (const auto& [k, v] : headers) setHeader(k, v);
}

auto request::setParameter(std::string_view param,
                           std::string_view value) noexcept -> void {
    const std::string name {param};
    _params[name] = value;
}

auto request::setParameters(
    std::initializer_list<std::pair<std::string_view, std::string_view>>
        params) noexcept -> void {
    for (const auto& [k, v] : params) setParameter(k, v);
}

auto request::setPostField(std::string_view field,
                           std::string_view value) noexcept -> void {
    const std::string name {field};
    _postFields[name] = value;
}

auto request::setPostFields(
    std::initializer_list<std::pair<std::string_view, std::string_view>>
        fields) noexcept -> void {
    for (const auto& [k, v] : fields) setPostField(k, v);
}
} // namespace libcurl
