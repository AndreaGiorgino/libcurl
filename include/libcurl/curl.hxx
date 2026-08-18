#pragma once

#include <future>
#include <libcurl/request.hxx>
#include <libcurl/response.hxx>

namespace libcurl {
/**
 * @brief Send a request and receive an asynchronous response
 *
 * @param req The request to send
 */
[[nodiscard]] auto curl(request req) -> std::future<response>;
} // namespace libcurl
