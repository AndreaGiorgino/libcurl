#include <helpers.hxx>
#include <libcurl/response.hxx>
#include <utility>

using libcurl::headers;
using libcurl::response;
using libcurl::status_codes;

auto TestResponse_Ctors(int, char**) -> int {
    constexpr auto expectedUrl {"https://example.com"};

    constexpr auto expectedStatusCode {status_codes::OK};

    const std::unordered_map<std::string, std::string> expectedHeaders {
        {"Content-Type",  "application/json" },
        {"x-Test-Header", "Test header value"},
    };

    const std::unordered_map<std::string, std::string> expectedParameters {
        {"param0", "value0"},
        {"param1", "value1"},
    };

    constexpr auto expectedBody {"{ data: \"Some json data\" }"};

    // default
    const response res0 {};

    helpers::checkeq(res0.getUrl(), "");
    helpers::checkeq(std::to_underlying(res0.getStatusCode()),
                     std::to_underlying(status_codes::NOT_EXECUTED));
    helpers::checkeqDict(res0.getHeaders(), {});
    helpers::checkeq(res0.getBody(), "");

    // initial values
    const response res1 {
        expectedUrl,
        expectedStatusCode,
        {
          {headers::CONTENT_TYPE, "application/json"},
          {"x-Test-Header", "Test header value"},
          },
        expectedBody,
    };

    helpers::checkeq(res1.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(res1.getStatusCode()),
                     std::to_underlying(expectedStatusCode));
    helpers::checkeqDict(res1.getHeaders(), expectedHeaders);
    helpers::checkeq(res1.getBody(), expectedBody);

    // copy
    const auto res2 {res1};

    helpers::checkeq(res2.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(res2.getStatusCode()),
                     std::to_underlying(expectedStatusCode));
    helpers::checkeqDict(res2.getHeaders(), expectedHeaders);
    helpers::checkeq(res2.getBody(), expectedBody);

    // move
    auto buffer {res1};
    const auto res3 {std::move(buffer)};

    helpers::checkeq(res3.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(res3.getStatusCode()),
                     std::to_underlying(expectedStatusCode));
    helpers::checkeqDict(res3.getHeaders(), expectedHeaders);
    helpers::checkeq(res3.getBody(), expectedBody);

    helpers::checkeq(buffer.getUrl(), res0.getUrl());
    helpers::checkeqDict(buffer.getHeaders(), res0.getHeaders());
    helpers::checkeq(buffer.getBody(), res0.getBody());

    return 0;
}
