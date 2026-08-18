#include <helpers.hxx>
#include <libcurl/curl.hxx>
#include <libjson/extra/decode.hxx>

using libcurl::headers;
using libcurl::request;

auto TestRequest_Headers(int, char**) -> int {
    request req {helpers::API_URL + "/headers"};

    req.setHeaders({
        {headers::CONTENT_TYPE, "application/json" },
        {"X-Test-Header",       "Test header value"},
    });

    auto future {libcurl::curl(req)};
    future.wait();

    const auto res {future.get()};

    const auto body {res.getBody()};
    const auto node {libjson::decode(body)};
    const auto headers {node.at("headers")};

    // check headers
    helpers::checkeq(headers.at("Content-Type").as<std::string>(),
                     "application/json");
    helpers::checkeq(headers.at("X-Test-Header").as<std::string>(),
                     "Test header value");

    return 0;
}
