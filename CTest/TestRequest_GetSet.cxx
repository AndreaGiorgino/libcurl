#include <helpers.hxx>
#include <libcurl/request.hxx>
#include <utility>

using libcurl::headers;
using libcurl::methods;
using libcurl::request;

auto TestRequest_GetSet(int, char**) -> int {
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

    request req {};

    req.setUrl(expectedUrl);
    req.setMethod(expectedMethod);

    req.setHeaders({
        {headers::CONTENT_TYPE, "application/json" },
        {"x-Test-Header",       "Test header value"},
    });

    req.setParameters({
        {"param0", "value0"},
        {"param1", "value1"},
    });

    req.setPostFields({
        {"field0", "value0"},
        {"field1", "value1"},
    });

    helpers::checkeq(req.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(req.getMethod()),
                     std::to_underlying(expectedMethod));
    helpers::checkeqDict(req.getHeaders(), expectedHeaders);
    helpers::checkeqDict(req.getParameters(), expectedParameters);
    helpers::checkeqDict(req.getPostFields(), expectedPostFields);

    return 0;
}
