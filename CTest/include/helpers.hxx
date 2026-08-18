#pragma once

#include <sstream>
#include <stdexcept>
#include <unordered_map>

namespace helpers {
const std::string API_URL {"https://httpbun.com"};

template <typename Tp, typename Up>
auto checkeq(const Tp& lhs, const Up& rhs) -> void {
    if (lhs == rhs) return;

    std::stringstream ss;
    ss << "Values not equals:" << std::endl
       << "  1. " << lhs << std::endl
       << "  2. " << rhs << std::endl;

    throw std::runtime_error(ss.str());
}

auto checkeqDict(const std::unordered_map<std::string, std::string>& lhs,
    const std::unordered_map<std::string, std::string>& rhs) -> void;
} // namespace helpers
