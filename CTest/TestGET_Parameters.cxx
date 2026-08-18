#include <helpers.hxx>
#include <libcurl/curl.hxx>
#include <libjson/extra/decode.hxx>

using libcurl::methods;
using libcurl::request;
using libcurl::status_codes;

auto TestGET_Parameters(int, char**) -> int {
    const request req {
        helpers::API_URL + "/get", methods::GET, {},
        {{"param1", "value1"}, {"param2", "value2"}}
    };

    auto future {libcurl::curl(req)};
    future.wait();

    const auto res {future.get()};

    // check status code
    helpers::checkeq(getStatusCodeValue(res.getStatusCode()),
        getStatusCodeValue(status_codes::OK));

    const auto body {res.getBody()};
    const auto node {libjson::decode(body)};
    const auto args {node.at("args")};

    // check params
    helpers::checkeq(args.at("param1").as<std::string>(), "value1");
    helpers::checkeq(args.at("param2").as<std::string>(), "value2");

    return 0;
}
