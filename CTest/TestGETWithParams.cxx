#include <helpers.hxx>
#include <libcurl/curl.hxx>

using libcurl::methods;
using libcurl::request;
using libcurl::status_codes;

auto TestGETWithParams(int, char**) -> int {
    const request req {
        "https://cataas.com/cat", methods::GET, {}, {{"json", "true"}}};

    auto future {libcurl::get(req)};
    future.wait();

    const auto res {future.get()};

    // check status code
    helpers::checkeq(getStatusCodeValue(res.getStatusCode()),
        getStatusCodeValue(status_codes::OK));

    // check headers
    helpers::checkeq(res.getHeader("access-control-allow-headers"),
        "X-Requested-With, Content-Type, Accept, Origin, Authorization");
    helpers::checkeq(res.getHeader("access-control-allow-methods"),
        "GET, POST, PUT, DELETE, OPTIONS");
    helpers::checkeq(res.getHeader("access-control-allow-origin"), "*");
    helpers::checkeq(
        res.getHeader("content-type"), "application/json; charset=utf-8");

    return 0;
}
