#include <helpers.hxx>
#include <libcurl/curl.hxx>
#include <libjson/extra/decode.hxx>

using libcurl::methods;
using libcurl::request;

auto TestRequest_PostFields(int, char**) -> int {
    request req {helpers::API_URL + "/post", methods::POST};

    req.setPostFields({
        {"param0", "value0"},
        {"param1", "value1"},
    });

    auto future {libcurl::curl(req)};
    future.wait();

    const auto res {future.get()};

    const auto body {res.getBody()};
    const auto node {libjson::decode(body)};
    const auto form {node.at("form")};

    // check post fields
    helpers::checkeq(form.at("param0").as<std::string>(), "value0");
    helpers::checkeq(form.at("param1").as<std::string>(), "value1");

    return 0;
}
