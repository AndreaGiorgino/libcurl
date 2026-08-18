#include <helpers.hxx>
#include <libcurl/request.hxx>
#include <utility>

using libcurl::headers;
using libcurl::methods;
using libcurl::request;

auto TestRequest_Ctors(int, char**) -> int {
    constexpr auto expectedUrl {"https://example.com"};

    constexpr auto expectedMethod {methods::POST};

    const std::unordered_map<std::string, std::string> expectedHeaders {
        {"Content-Type",  "application/json" },
        {"x-Test-Header", "Test header value"},
    };

    const std::unordered_map<std::string, std::string> expectedParameters {
        {"param0", "value0"},
        {"param1", "value1"},
    };

    const std::unordered_map<std::string, std::string> expectedPostFields {
        {"field0", "value0"},
        {"field1", "value1"},
    };

    // default
    const request req0 {};

    helpers::checkeq(req0.getUrl(), "");
    helpers::checkeq(std::to_underlying(req0.getMethod()),
                     std::to_underlying(methods::GET));
    helpers::checkeqDict(req0.getHeaders(), {});
    helpers::checkeqDict(req0.getParameters(), {});
    helpers::checkeqDict(req0.getPostFields(), {});

    // initial values
    const request req1 {
        expectedUrl,
        expectedMethod,
        {
          {headers::CONTENT_TYPE, "application/json"},
          {"x-Test-Header", "Test header value"},
          },
        {
          {"param0", "value0"},
          {"param1", "value1"},
          },
        {
          {"field0", "value0"},
          {"field1", "value1"},
          }
    };

    helpers::checkeq(req1.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(req1.getMethod()),
                     std::to_underlying(expectedMethod));
    helpers::checkeqDict(req1.getHeaders(), expectedHeaders);
    helpers::checkeqDict(req1.getParameters(), expectedParameters);
    helpers::checkeqDict(req1.getPostFields(), expectedPostFields);

    // copy
    const auto req2 {req1};

    helpers::checkeq(req2.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(req2.getMethod()),
                     std::to_underlying(expectedMethod));
    helpers::checkeqDict(req2.getHeaders(), expectedHeaders);
    helpers::checkeqDict(req2.getParameters(), expectedParameters);
    helpers::checkeqDict(req2.getPostFields(), expectedPostFields);

    // move
    auto buffer {req1};
    const auto req3 {std::move(buffer)};

    helpers::checkeq(req3.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(req3.getMethod()),
                     std::to_underlying(expectedMethod));
    helpers::checkeqDict(req3.getHeaders(), expectedHeaders);
    helpers::checkeqDict(req3.getParameters(), expectedParameters);
    helpers::checkeqDict(req3.getPostFields(), expectedPostFields);

    helpers::checkeq(buffer.getUrl(), req0.getUrl());
    helpers::checkeqDict(buffer.getHeaders(), req0.getHeaders());
    helpers::checkeqDict(buffer.getParameters(), req0.getParameters());
    helpers::checkeqDict(buffer.getPostFields(), req0.getPostFields());

    return 0;
}
