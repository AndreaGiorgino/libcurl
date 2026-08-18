#include <helpers.hxx>
#include <libcurl/curl.hxx>
#include <utility>

using libcurl::request;
using libcurl::status_codes;

auto TestGET(int, char**) -> int {
    const request req {helpers::API_URL + "/get"};

    auto future {libcurl::curl(req)};
    future.wait();

    const auto res {future.get()};

    // check status code
    helpers::checkeq(std::to_underlying(res.getStatusCode()),
                     std::to_underlying(status_codes::OK));

    return 0;
}
