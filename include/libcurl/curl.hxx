#pragma once

#include <future>
#include <libcurl/request.hxx>
#include <libcurl/response.hxx>

namespace libcurl {
/**
 * @brief Send a request and receive a response
 *
 * @param req The request
 */
[[nodiscard]] auto get(request req) -> std::future<response>;
} // namespace libcurl
