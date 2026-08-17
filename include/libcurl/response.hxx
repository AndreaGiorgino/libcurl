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

    response(std::string_view url, status_codes statusCode,
        std::initializer_list<std::pair<std::variant<headers, std::string_view>,
            std::string_view>>
            headers           = {},
        std::string_view body = {}) noexcept;

    response(const response&) noexcept                     = default;
    auto operator =(const response&) noexcept -> response& = default;

    response(response&&) noexcept                     = default;
    auto operator =(response&&) noexcept -> response& = default;

    ~response(void) noexcept = default;

   public:
    // ----------- Lookup -----------

    /**
     * @brief Get the requested url
     */
    [[nodiscard]] auto getUrl(void) const noexcept -> std::string;

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

    /**
     * @brief Get the response body
     */
    [[nodiscard]] auto getBody(void) const noexcept -> std::string;

    // ------------------------------

    // --------- Modifiers ----------

    /**
     * @brief Set the requested url
     *
     * @param url The url to set
     */
    auto setUrl(std::string_view url) noexcept -> void;

    /**
     * @brief Set the response status code
     *
     * @param statusCode The status code
     */
    auto setStatusCode(status_codes statusCode) noexcept -> void;

    /**
     * @brief Set/Add the response header
     *
     * @param header The header to set/add
     * @param value The value to assign to the header
     */
    auto setHeader(std::variant<headers, std::string_view> header,
        std::string_view value) noexcept -> void;

    /**
     * @brief Set/Add the response headers
     *
     * @param headers The values to assign to the headers
     */
    auto setHeaders(std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
            headers) noexcept -> void;

    /**
     * @brief Set the response body
     *
     * @param body The value to assign to the body
     */
    auto setBody(std::string_view body) noexcept -> void;

    // ------------------------------
   private: // members
    std::string _url {};
    status_codes _statusCode {status_codes::NOT_EXECUTED};

    std::unordered_map<std::string, std::string> _headers {};
    std::string _body {};
};
} // namespace libcurl
