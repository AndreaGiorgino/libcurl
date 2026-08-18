#include <helpers.hxx>
#include <libcurl/headers.hxx>

using libcurl::headers;

auto TestHeaders_GetName(int, char**) -> int {
    helpers::checkeq(
        libcurl::getHeaderName(headers::WWW_AUTHENTICATE), "WWW-Authenticate");
    helpers::checkeq(
        libcurl::getHeaderName(headers::AUTHORIZATION), "Authorization");
    helpers::checkeq(libcurl::getHeaderName(headers::PROXY_AUTHENTICATE),
        "Proxy-Authenticate");
    helpers::checkeq(libcurl::getHeaderName(headers::PROXY_AUTHORIZATION),
        "Proxy-Authorization");
    helpers::checkeq(libcurl::getHeaderName(headers::AGE), "Age");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CACHE_CONTROL), "Cache-Control");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CLEAR_SITE_DATA), "Clear-Site-Data");
    helpers::checkeq(libcurl::getHeaderName(headers::EXPIRES), "Expires");
    helpers::checkeq(
        libcurl::getHeaderName(headers::LAST_MODIFIED), "Last-Modified");
    helpers::checkeq(libcurl::getHeaderName(headers::ETAG), "ETag");
    helpers::checkeq(libcurl::getHeaderName(headers::IF_MATCH), "If-Match");
    helpers::checkeq(
        libcurl::getHeaderName(headers::IF_NONE_MATCH), "If-None-Match");
    helpers::checkeq(libcurl::getHeaderName(headers::IF_MODIFIED_SINCE),
        "If-Modified-Since");
    helpers::checkeq(libcurl::getHeaderName(headers::IF_UNMODIFIED_SINCE),
        "If-Unmodified-Since");
    helpers::checkeq(libcurl::getHeaderName(headers::VARY), "Vary");
    helpers::checkeq(libcurl::getHeaderName(headers::CONNECTION), "Connection");
    helpers::checkeq(libcurl::getHeaderName(headers::KEEP_ALIVE), "Keep-Alive");
    helpers::checkeq(libcurl::getHeaderName(headers::ACCEPT), "Accept");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCEPT_ENCODING), "Accept-Encoding");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCEPT_LANGUAGE), "Accept-Language");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCEPT_PATCH), "Accept-Patch");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCEPT_POST), "Accept-Post");
    helpers::checkeq(libcurl::getHeaderName(headers::EXPECT), "Expect");
    helpers::checkeq(
        libcurl::getHeaderName(headers::MAX_FORWARDS), "Max-Forwards");
    helpers::checkeq(libcurl::getHeaderName(headers::COOKIE), "Cookie");
    helpers::checkeq(libcurl::getHeaderName(headers::SET_COOKIE), "Set-Cookie");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_ALLOW_CREDENTIALS),
        "Access-Control-Allow-Credentials");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_ALLOW_HEADERS),
        "Access-Control-Allow-Headers");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_ALLOW_METHODS),
        "Access-Control-Allow-Methods");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_ALLOW_ORIGIN),
        "Access-Control-Allow-Origin");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_EXPOSE_HEADERS),
        "Access-Control-Expose-Headers");
    helpers::checkeq(libcurl::getHeaderName(headers::ACCESS_CONTROL_MAX_AGE),
        "Access-Control-Max-Age");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_REQUEST_HEADERS),
        "Access-Control-Request-Headers");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCESS_CONTROL_REQUEST_METHOD),
        "Access-Control-Request-Method");
    helpers::checkeq(libcurl::getHeaderName(headers::ORIGIN), "Origin");
    helpers::checkeq(libcurl::getHeaderName(headers::TIMING_ALLOW_ORIGIN),
        "Timing-Allow-Origin");
    helpers::checkeq(libcurl::getHeaderName(headers::CONTENT_DISPOSITION),
        "Content-Disposition");
    helpers::checkeq(
        libcurl::getHeaderName(headers::INTEGRITY_POLICY), "Integrity-Policy");
    helpers::checkeq(
        libcurl::getHeaderName(headers::INTEGRITY_POLICY_REPORT_ONLY),
        "Integrity-Policy-Report-Only");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_LENGTH), "Content-Length");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_TYPE), "Content-Type");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_ENCODING), "Content-Encoding");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_LANGUAGE), "Content-Language");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_LOCATION), "Content-Location");
    helpers::checkeq(libcurl::getHeaderName(headers::PREFER), "Prefer");
    helpers::checkeq(libcurl::getHeaderName(headers::PREFERENCE_APPLIED),
        "Preference-Applied");
    helpers::checkeq(libcurl::getHeaderName(headers::FORWARDED), "Forwarded");
    helpers::checkeq(libcurl::getHeaderName(headers::VIA), "Via");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ACCEPT_RANGES), "Accept-Ranges");
    helpers::checkeq(libcurl::getHeaderName(headers::RANGE), "Range");
    helpers::checkeq(libcurl::getHeaderName(headers::IF_RANGE), "If-Range");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_RANGE), "Content-Range");
    helpers::checkeq(libcurl::getHeaderName(headers::LOCATION), "Location");
    helpers::checkeq(libcurl::getHeaderName(headers::REFRESH), "Refresh");
    helpers::checkeq(libcurl::getHeaderName(headers::FROM), "From");
    helpers::checkeq(libcurl::getHeaderName(headers::HOST), "Host");
    helpers::checkeq(libcurl::getHeaderName(headers::REFERER), "Referer");
    helpers::checkeq(
        libcurl::getHeaderName(headers::REFERRER_POLICY), "Referrer-Policy");
    helpers::checkeq(libcurl::getHeaderName(headers::USER_AGENT), "User-Agent");
    helpers::checkeq(libcurl::getHeaderName(headers::ALLOW), "Allow");
    helpers::checkeq(libcurl::getHeaderName(headers::SERVER), "Server");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CROSS_ORIGIN_EMBEDDER_POLICY),
        "Cross-Origin-Embedder-Policy");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CROSS_ORIGIN_OPENER_POLICY),
        "Cross-Origin-Opener-Policy");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CROSS_ORIGIN_RESOURCE_POLICY),
        "Cross-Origin-Resource-Policy");
    helpers::checkeq(libcurl::getHeaderName(headers::CONTENT_SECURITY_POLICY),
        "Content-Security-Policy");
    helpers::checkeq(
        libcurl::getHeaderName(headers::CONTENT_SECURITY_POLICY_REPORT_ONLY),
        "Content-Security-Policy-Report-Only");
    helpers::checkeq(libcurl::getHeaderName(headers::PERMISSIONS_POLICY),
        "Permissions-Policy");
    helpers::checkeq(libcurl::getHeaderName(headers::STRICT_TRANSPORT_SECURITY),
        "Strict-Transport-Security");
    helpers::checkeq(libcurl::getHeaderName(headers::UPGRADE_INSECURE_REQUESTS),
        "Upgrade-Insecure-Requests");
    helpers::checkeq(libcurl::getHeaderName(headers::X_CONTENT_TYPE_OPTIONS),
        "X-Content-Type-Options");
    helpers::checkeq(
        libcurl::getHeaderName(headers::X_FRAME_OPTIONS), "X-Frame-Options");
    helpers::checkeq(
        libcurl::getHeaderName(headers::X_PERMITTED_CROSS_DOMAIN_POLICIES),
        "X-Permitted-Cross-Domain-Policies");
    helpers::checkeq(
        libcurl::getHeaderName(headers::X_POWERED_BY), "X-Powered-By");
    helpers::checkeq(
        libcurl::getHeaderName(headers::X_XSS_PROTECTION), "X-XSS-Protection");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SEC_FETCH_SITE), "Sec-Fetch-Site");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SEC_FETCH_MODE), "Sec-Fetch-Mode");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SEC_FETCH_USER), "Sec-Fetch-User");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SEC_FETCH_DEST), "Sec-Fetch-Dest");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SEC_PURPOSE), "Sec-Purpose");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SERVICE_WORKER_NAVIGATION_PRELOAD),
        "Service-Worker-Navigation-Preload");
    helpers::checkeq(libcurl::getHeaderName(headers::SEC_FETCH_STORAGE_ACCESS),
        "Sec-Fetch-Storage-Access");
    helpers::checkeq(libcurl::getHeaderName(headers::ACTIVATE_STORAGE_ACCESS),
        "Activate-Storage-Access");
    helpers::checkeq(libcurl::getHeaderName(headers::REPORTING_ENDPOINTS),
        "Reporting-Endpoints");
    helpers::checkeq(libcurl::getHeaderName(headers::TRANSFER_ENCODING),
        "Transfer-Encoding");
    helpers::checkeq(libcurl::getHeaderName(headers::TE), "TE");
    helpers::checkeq(libcurl::getHeaderName(headers::TRAILER), "Trailer");
    helpers::checkeq(libcurl::getHeaderName(headers::SEC_WEBSOCKET_ACCEPT),
        "Sec-WebSocket-Accept");
    helpers::checkeq(libcurl::getHeaderName(headers::SEC_WEBSOCKET_EXTENSIONS),
        "Sec-WebSocket-Extensions");
    helpers::checkeq(libcurl::getHeaderName(headers::SEC_WEBSOCKET_KEY),
        "Sec-WebSocket-Key");
    helpers::checkeq(libcurl::getHeaderName(headers::SEC_WEBSOCKET_PROTOCOL),
        "Sec-WebSocket-Protocol");
    helpers::checkeq(libcurl::getHeaderName(headers::SEC_WEBSOCKET_VERSION),
        "Sec-WebSocket-Version");
    helpers::checkeq(libcurl::getHeaderName(headers::ALT_SVC), "Alt-Svc");
    helpers::checkeq(libcurl::getHeaderName(headers::ALT_USED), "Alt-Used");
    helpers::checkeq(libcurl::getHeaderName(headers::DATE), "Date");
    helpers::checkeq(libcurl::getHeaderName(headers::LINK), "Link");
    helpers::checkeq(
        libcurl::getHeaderName(headers::RETRY_AFTER), "Retry-After");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SERVER_TIMING), "Server-Timing");
    helpers::checkeq(
        libcurl::getHeaderName(headers::SERVICE_WORKER), "Service-Worker");
    helpers::checkeq(libcurl::getHeaderName(headers::SERVICE_WORKER_ALLOWED),
        "Service-Worker-Allowed");
    helpers::checkeq(libcurl::getHeaderName(headers::SOURCEMAP), "SourceMap");
    helpers::checkeq(libcurl::getHeaderName(headers::UPGRADE), "Upgrade");
    helpers::checkeq(libcurl::getHeaderName(headers::PRIORITY), "Priority");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ATTRIBUTION_REPORTING_ELIGIBLE),
        "Attribution-Reporting-Eligible");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ATTRIBUTION_REPORTING_REGISTER_SOURCE),
        "Attribution-Reporting-Register-Source");
    helpers::checkeq(
        libcurl::getHeaderName(headers::ATTRIBUTION_REPORTING_REGISTER_TRIGGER),
        "Attribution-Reporting-Register-Trigger");
    helpers::checkeq(libcurl::getHeaderName(headers::ACCEPT_CH), "Accept-CH");

    try {
        (void)getHeaderName((headers)(1 << 30));
        return 1;
    } catch (...) {
        return 0;
    }
}
