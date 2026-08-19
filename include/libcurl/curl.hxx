#pragma once

#include <future>
#include <libcurl/request.hxx>
#include <libcurl/response.hxx>

namespace libcurl {
/**
 * @brief Send a request and receive an asynchronous response
 *
 * @param req The request to send
 *
 * @throws std::runtime_error If a parameter cannot be escaped
 * @throws std::runtime_error If the header 'Content-Type: application/json' is
 * present but more than one post field has been provided
 * @throws std::runtime_error If a post field cannot be escaped
 * @throws std::runtime_error If the CURL object cannot be initialized
 * @throws std::runtime_error If the CURL object failed to send the request
 */
[[nodiscard]] auto curl(request req) -> std::future<response>;
} // namespace libcurl
