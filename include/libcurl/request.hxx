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

   public:  // methods
   private: // methods
   private: // members
};
} // namespace libcurl
