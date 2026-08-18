#include <helpers.hxx>
#include <libcurl/methods.hxx>

using libcurl::methods;

auto TestMethods_GetName(int, char**) -> int {
    helpers::checkeq(libcurl::getMethodName(methods::DELETE), "DELETE");
    helpers::checkeq(libcurl::getMethodName(methods::GET), "GET");
    helpers::checkeq(libcurl::getMethodName(methods::HEAD), "HEAD");
    helpers::checkeq(libcurl::getMethodName(methods::OPTIONS), "OPTIONS");
    helpers::checkeq(libcurl::getMethodName(methods::PATCH), "PATCH");
    helpers::checkeq(libcurl::getMethodName(methods::POST), "POST");
    helpers::checkeq(libcurl::getMethodName(methods::PUT), "PUT");
    helpers::checkeq(libcurl::getMethodName(methods::TRACE), "TRACE");

    try {
        (void)libcurl::getMethodName((methods)(999));
        return 1;
    } catch (...) {
        return 0;
    }
}
