#pragma once

#include <libcurl/headers.hxx>
#include <libcurl/methods.hxx>
#include <variant>

namespace libcurl {
class request final {
   public: // definitions
   public: // ctors
    request(void) noexcept = default;

    request(std::string_view url, methods method = methods::GET,
        std::initializer_list<std::pair<std::variant<headers, std::string_view>,
            std::string_view>>
            headers = {}) noexcept;

    request(const request&) noexcept                     = default;
    auto operator =(const request&) noexcept -> request& = default;

    request(request&&) noexcept                     = default;
    auto operator =(request&&) noexcept -> request& = default;

    ~request(void) noexcept = default;

   public: // methods
    /**
     * @brief Set the request target url
     *
     * @param url The target url
     */
    auto setUrl(std::string_view url) noexcept -> void;

    /**
     * @brief Set the request method
     *
     * @param method The method
     */
    auto setMethod(methods method) noexcept -> void;

    /**
     * @brief Set/Add the request header
     *
     * @param header The header to set/add
     * @param value The value to assign to the header
     */
    auto setHeader(std::variant<headers, std::string_view> header,
        std::string_view value) noexcept -> void;

    /**
     * @brief Set/Add the request headers
     *
     * @param headers The values to assign to the headers
     */
    auto setHeaders(std::initializer_list<
        std::pair<std::variant<headers, std::string_view>, std::string_view>>
            headers) noexcept;

   private: // methods
   private: // members
};
} // namespace libcurl
