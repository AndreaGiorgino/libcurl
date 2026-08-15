#include <libcurl/methods.hxx>
#include <stdexcept>

namespace libcurl {
auto getMethodName(methods method) -> std::string {
    switch (method) {
        case methods::DELETE:
            return "DELETE";
        case methods::GET:
            return "GET";
        case methods::HEAD:
            return "HEAD";
        case methods::OPTIONS:
            return "OPTIONS";
        case methods::PATCH:
            return "PATCH";
        case methods::POST:
            return "POST";
        case methods::PUT:
            return "PUT";
        case methods::TRACE:
            return "TRACE";
        default: // unreachable
            throw std::logic_error("Method not implemented");
    }
}
} // namespace libcurl
