// source: https://developer.mozilla.org/docs/Web/HTTP/Reference/Methods

#pragma once

#include <string>

namespace libcurl {
/*
 * @brief Represents the allowed methods
 */
enum class methods {
    DELETE,
    GET,
    HEAD,
    OPTIONS,
    PATCH,
    POST,
    PUT,
    TRACE,
};

/**
 * @brief Get the string representation of the method
 *
 * @param method The method enum
 *
 * @throws std::logic_error If the method has not been implemented, should be
 * unreachable
 */
[[nodiscard]] auto getMethodName(methods method) -> std::string;
} // namespace libcurl
