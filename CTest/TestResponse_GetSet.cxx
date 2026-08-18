#include <helpers.hxx>
#include <libcurl/response.hxx>
#include <utility>

using libcurl::headers;
using libcurl::response;
using libcurl::status_codes;

auto TestResponse_GetSet(int, char**) -> int {
    constexpr auto expectedUrl {"https://example.com"};

    constexpr auto expectedStatusCode {status_codes::OK};

    const std::unordered_map<std::string, std::string> expectedHeaders {
        {"Content-Type",  "application/json" },
        {"x-Test-Header", "Test header value"},
    };

    constexpr auto expectedBody {"{ data: \"Some json data\" }"};

    response res {};

    res.setUrl(expectedUrl);
    res.setStatusCode(expectedStatusCode);

    res.setHeaders({
        {headers::CONTENT_TYPE, "application/json" },
        {"x-Test-Header",       "Test header value"},
    });

    res.setBody(expectedBody);

    helpers::checkeq(res.getUrl(), expectedUrl);
    helpers::checkeq(std::to_underlying(res.getStatusCode()),
                     std::to_underlying(expectedStatusCode));
    helpers::checkeqDict(res.getHeaders(), expectedHeaders);
    helpers::checkeq(res.getBody(), expectedBody);

    return 0;
}
