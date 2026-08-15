#pragma once

namespace libcurl {
class curl final {
   public: // definitions
   public: // ctors
    curl(void) = default;

    curl(const curl&)                     = default;
    auto operator =(const curl&) -> curl& = default;

    curl(curl&&)                     = default;
    auto operator =(curl&&) -> curl& = default;

    ~curl(void) = default;

   public:  // methods
   private: // methods
   private: // members
};
} // namespace libcurl
