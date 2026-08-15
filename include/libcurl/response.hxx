#pragma once

#include <libcurl/headers.hxx>
#include <libcurl/status_codes.hxx>
#include <unordered_map>
#include <variant>

namespace libcurl {
/**
 * @class response
 * @brief Represents an http response
 *
 */
class response final {
   public: // ctors
    response(void) noexcept = default;

    response(const response&) noexcept                     = default;
    auto operator =(const response&) noexcept -> response& = default;

    response(response&&) noexcept                     = default;
    auto operator =(response&&) noexcept -> response& = default;

    ~response(void) noexcept = default;
   private: // members
    std::unordered_map<std::string, std::string> _headers {};
    status_codes _statusCode {status_codes::NOT_EXECUTED};
};
} // namespace libcurl
