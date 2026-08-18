#include <helpers.hxx>
#include <libcurl/status_codes.hxx>

using libcurl::status_codes;

auto TestStatusCodes_GetName(int, char**) -> int {
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NOT_EXECUTED),
                     "Not Executed");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::CONTINUE),
                     "Continue");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::SWITCHING_PROTOCOLS),
        "Switching Protocols");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::EARLY_HINTS),
                     "Early Hints");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::OK), "OK");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::CREATED),
                     "Created");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::ACCEPTED),
                     "Accepted");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::NON_AUTHORITATIVE_INFORMATION),
        "Non-Authoritative Information");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NO_CONTENT),
                     "No Content");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::RESET_CONTENT),
                     "Reset Content");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::PARTIAL_CONTENT),
                     "Partial Content");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::MULTI_STATUS),
                     "Multi-Status");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::ALREADY_REPORTED),
                     "Already Reported");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::IM_USED),
                     "IM Used");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::MULTIPLE_CHOICES),
                     "Multiple Choices");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::MOVED_PERMANENTLY),
        "Moved Permanently");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::FOUND), "Found");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::SEE_OTHER),
                     "See Other");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NOT_MODIFIED),
                     "Not Modified");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::UNUSED),
                     "unused");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::TEMPORARY_REDIRECT),
        "Temporary Redirect");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::PERMANENT_REDIRECT),
        "Permanent Redirect");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::BAD_REQUEST),
                     "Bad Request");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::UNAUTHORIZED),
                     "Unauthorized");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::PAYMENT_REQUIRED),
                     "Payment Required");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::FORBIDDEN),
                     "Forbidden");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NOT_FOUND),
                     "Not Found");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::METHOD_NOT_ALLOWED),
        "Method Not Allowed");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NOT_ACCEPTABLE),
                     "Not Acceptable");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::PROXY_AUTHENTICATION_REQUIRED),
        "Proxy Authentication Required");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::REQUEST_TIMEOUT),
                     "Request Timeout");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::CONFLICT),
                     "Conflict");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::GONE), "Gone");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::LENGTH_REQUIRED),
                     "Length Required");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::PRECONDITION_FAILED),
        "Precondition Failed");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::CONTENT_TOO_LARGE),
        "Content Too Large");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::URI_TOO_LONG),
                     "URI Too Long");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::UNSUPPORTED_MEDIA_TYPE),
        "Unsupported Media Type");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::RANGE_NOT_SATISFIABLE),
        "Range Not Satisfiable");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::EXPECTATION_FAILED),
        "Expectation Failed");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::MISDIRECTED_REQUEST),
        "Misdirected Request");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::UNPROCESSABLE_CONTENT),
        "Unprocessable Content");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::LOCKED),
                     "Locked");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::FAILED_DEPENDENCY),
        "Failed Dependency");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::UPGRADE_REQUIRED),
                     "Upgrade Required");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::PRECONDITION_REQUIRED),
        "Precondition Required");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::TOO_MANY_REQUESTS),
        "Too Many Requests");
    helpers::checkeq(libcurl::getStatusCodeName(
                         status_codes::REQUEST_HEADER_FIELDS_TOO_LARGE),
                     "Request Header Fields Too Large");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::UNAVAILABLE_FOR_LEGAL_REASONS),
        "Unavailable For Legal Reasons");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::INTERNAL_SERVER_ERROR),
        "Internal Server Error");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NOT_IMPLEMENTED),
                     "Not Implemented");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::BAD_GATEWAY),
                     "Bad Gateway");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::SERVICE_UNAVAILABLE),
        "Service Unavailable");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::GATEWAY_TIMEOUT),
                     "Gateway Timeout");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::HTTP_VERSION_NOT_SUPPORTED),
        "HTTP Version Not Supported");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::VARIANT_ALSO_NEGOTIATES),
        "Variant Also Negotiates");
    helpers::checkeq(
        libcurl::getStatusCodeName(status_codes::INSUFFICIENT_STORAGE),
        "Insufficient Storage");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::LOOP_DETECTED),
                     "Loop Detected");
    helpers::checkeq(libcurl::getStatusCodeName(status_codes::NOT_EXTENDED),
                     "Not Extended");
    helpers::checkeq(libcurl::getStatusCodeName(
                         status_codes::NETWORK_AUTHENTICATION_REQUIRED),
                     "Network Authentication Required");
    helpers::checkeq(libcurl::getStatusCodeName((status_codes)999),
                     "Not Standard - 999");

    return 0;
}
