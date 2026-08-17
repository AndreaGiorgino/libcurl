#pragma once

#include <libcurl/headers.hxx>
#include <libcurl/methods.hxx>
#include <unordered_map>
#include <variant>

namespace libcurl {
/**
 * @class request
 * @brief Represents an http request
 *
 */
class request final {
   public: // ctors
    request(void) noexcept = default;

    request(std::string_view url, methods method = methods::GET,
        std::initializer_list<std::pair<std::variant<headers, std::string_view>,
            std::string_view>>
            headers = {},
        std::initializer_list<std::pair<std::string_view, std::string_view>>
            params = {}) noexcept;

    request(const request&) noexcept                     = default;
    auto operator =(const request&) noexcept -> request& = default;

    request(request&&) noexcept                     = default;
    auto operator =(request&&) noexcept -> request& = default;

    ~request(void) noexcept = default;

   public:
    // ----------- Lookup -----------

    /**
     * @brief Get the request target url
     */
    [[nodiscard]] auto getUrl(void) const noexcept -> std::string;

    /**
     * @brief Get the request method
     */
    [[nodiscard]] auto getMethod(void) const noexcept -> methods;

    /**
     * @brief Get the request header value
     *
     * @param header The header to lookup
     */
    [[nodiscard]] auto getHeader(
        std::variant<headers, std::string_view> header) const noexcept
        -> std::string;

    /**
     * @brief Get the request headers collection
     */
    [[nodiscard]] auto getHeaders(void) const noexcept
        -> std::unordered_map<std::string, std::string>;

    /**
     * @brief Get the request parameter value
     *
     * @param param The parameter to lookup
     */
    [[nodiscard]] auto getParameter(std::string_view param) const noexcept
        -> std::string;

    /**
     * @brief Get the request parameters collection
     */
    [[nodiscard]] auto getParameters(void) const noexcept
        -> std::unordered_map<std::string, std::string>;

    // ------------------------------

    // --------- Modifiers ----------

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
            headers) noexcept -> void;

    /**
     * @brief Set/Add the request parameter
     *
     * @param param The parameter to set/add
     * @param value The value to assign to the parameter
     */
    auto setParameter(std::string_view param, std::string_view value) noexcept
        -> void;

    /**
     * @brief Set/Add the request parameters
     *
     * @param params The values to assign to the parameters
     */
    auto setParameters(
        std::initializer_list<std::pair<std::string_view, std::string_view>>
            params) noexcept -> void;

    // ------------------------------
   private: // members
    std::string _url {};
    methods _method {methods::GET};

    std::unordered_map<std::string, std::string> _headers {};
    std::unordered_map<std::string, std::string> _params {};
};
} // namespace libcurl
