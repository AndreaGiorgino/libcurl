#include <format>
#include <libcurl/status_codes.hxx>
#include <utility>

namespace libcurl {
auto getStatusCodeName(status_codes statusCode) -> std::string {
    switch (statusCode) {
        case status_codes::NOT_EXECUTED:
            return "Not Executed";
        case status_codes::CONTINUE:
            return "Continue";
        case status_codes::SWITCHING_PROTOCOLS:
            return "Switching Protocols";
        case status_codes::EARLY_HINTS:
            return "Early Hints";
        case status_codes::OK:
            return "OK";
        case status_codes::CREATED:
            return "Created";
        case status_codes::ACCEPTED:
            return "Accepted";
        case status_codes::NON_AUTHORITATIVE_INFORMATION:
            return "Non-Authoritative Information";
        case status_codes::NO_CONTENT:
            return "No Content";
        case status_codes::RESET_CONTENT:
            return "Reset Content";
        case status_codes::PARTIAL_CONTENT:
            return "Partial Content";
        case status_codes::MULTI_STATUS:
            return "Multi-Status";
        case status_codes::ALREADY_REPORTED:
            return "Already Reported";
        case status_codes::IM_USED:
            return "IM Used";
        case status_codes::MULTIPLE_CHOICES:
            return "Multiple Choices";
        case status_codes::MOVED_PERMANENTLY:
            return "Moved Permanently";
        case status_codes::FOUND:
            return "Found";
        case status_codes::SEE_OTHER:
            return "See Other";
        case status_codes::NOT_MODIFIED:
            return "Not Modified";
        case status_codes::UNUSED:
            return "unused";
        case status_codes::TEMPORARY_REDIRECT:
            return "Temporary Redirect";
        case status_codes::PERMANENT_REDIRECT:
            return "Permanent Redirect";
        case status_codes::BAD_REQUEST:
            return "Bad Request";
        case status_codes::UNAUTHORIZED:
            return "Unauthorized";
        case status_codes::PAYMENT_REQUIRED:
            return "Payment Required";
        case status_codes::FORBIDDEN:
            return "Forbidden";
        case status_codes::NOT_FOUND:
            return "Not Found";
        case status_codes::METHOD_NOT_ALLOWED:
            return "Method Not Allowed";
        case status_codes::NOT_ACCEPTABLE:
            return "Not Acceptable";
        case status_codes::PROXY_AUTHENTICATION_REQUIRED:
            return "Proxy Authentication Required";
        case status_codes::REQUEST_TIMEOUT:
            return "Request Timeout";
        case status_codes::CONFLICT:
            return "Conflict";
        case status_codes::GONE:
            return "Gone";
        case status_codes::LENGTH_REQUIRED:
            return "Length Required";
        case status_codes::PRECONDITION_FAILED:
            return "Precondition Failed";
        case status_codes::CONTENT_TOO_LARGE:
            return "Content Too Large";
        case status_codes::URI_TOO_LONG:
            return "URI Too Long";
        case status_codes::UNSUPPORTED_MEDIA_TYPE:
            return "Unsupported Media Type";
        case status_codes::RANGE_NOT_SATISFIABLE:
            return "Range Not Satisfiable";
        case status_codes::EXPECTATION_FAILED:
            return "Expectation Failed";
        case status_codes::MISDIRECTED_REQUEST:
            return "Misdirected Request";
        case status_codes::UNPROCESSABLE_CONTENT:
            return "Unprocessable Content";
        case status_codes::LOCKED:
            return "Locked";
        case status_codes::FAILED_DEPENDENCY:
            return "Failed Dependency";
        case status_codes::UPGRADE_REQUIRED:
            return "Upgrade Required";
        case status_codes::PRECONDITION_REQUIRED:
            return "Precondition Required";
        case status_codes::TOO_MANY_REQUESTS:
            return "Too Many Requests";
        case status_codes::REQUEST_HEADER_FIELDS_TOO_LARGE:
            return "Request Header Fields Too Large";
        case status_codes::UNAVAILABLE_FOR_LEGAL_REASONS:
            return "Unavailable For Legal Reasons";
        case status_codes::INTERNAL_SERVER_ERROR:
            return "Internal Server Error";
        case status_codes::NOT_IMPLEMENTED:
            return "Not Implemented";
        case status_codes::BAD_GATEWAY:
            return "Bad Gateway";
        case status_codes::SERVICE_UNAVAILABLE:
            return "Service Unavailable";
        case status_codes::GATEWAY_TIMEOUT:
            return "Gateway Timeout";
        case status_codes::HTTP_VERSION_NOT_SUPPORTED:
            return "HTTP Version Not Supported";
        case status_codes::VARIANT_ALSO_NEGOTIATES:
            return "Variant Also Negotiates";
        case status_codes::INSUFFICIENT_STORAGE:
            return "Insufficient Storage";
        case status_codes::LOOP_DETECTED:
            return "Loop Detected";
        case status_codes::NOT_EXTENDED:
            return "Not Extended";
        case status_codes::NETWORK_AUTHENTICATION_REQUIRED:
            return "Network Authentication Required";
        default:
            return std::format("Not Standard - {}",
                               std::to_underlying(statusCode));
    }
}

auto isStatusCodeInformational(status_codes statusCode) noexcept -> bool {
    const auto val {std::to_underlying(statusCode)};
    return 100 <= val && val < 200;
}

auto isStatusCodeSuccess(status_codes statusCode) noexcept -> bool {
    const auto val {std::to_underlying(statusCode)};
    return 200 <= val && val < 300;
}

auto isStatusCodeRedirectionError(status_codes statusCode) noexcept -> bool {
    const auto val {std::to_underlying(statusCode)};
    return 300 <= val && val < 400;
}

auto isStatusCodeClientError(status_codes statusCode) noexcept -> bool {
    const auto val {std::to_underlying(statusCode)};
    return 400 <= val && val < 500;
}

auto isStatusCodeServerError(status_codes statusCode) noexcept -> bool {
    const auto val {std::to_underlying(statusCode)};
    return 500 <= val && val < 600;
}
} // namespace libcurl
