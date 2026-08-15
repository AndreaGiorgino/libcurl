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

   public:
    // ----------- Lookup -----------

    /**
     * @brief Get the response status code
     */
    [[nodiscard]] auto getStatusCode(void) const noexcept -> status_codes;

    /**
     * @brief Get the response header value
     *
     * @param header The header to lookup
     */
    [[nodiscard]] auto getHeader(
        std::variant<headers, std::string_view> header) const noexcept
        -> std::string;

    /**
     * @brief Get the response headers collection
     */
    [[nodiscard]] auto getHeaders(void) const noexcept
        -> std::unordered_map<std::string, std::string>;

    // ------------------------------

   private: // members
    std::unordered_map<std::string, std::string> _headers {};
    status_codes _statusCode {status_codes::NOT_EXECUTED};
};
} // namespace libcurl
