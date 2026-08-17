#pragma once

#include <sstream>
#include <stdexcept>

namespace helpers {
template <typename Tp, typename Up>
auto checkeq(Tp lhs, Up rhs) -> void {
    if (lhs == rhs) return;

    std::stringstream ss;
    ss << "Values are not equal:" << std::endl
       << "  1. " << lhs << std::endl
       << "  2. " << rhs << std::endl;

    throw std::runtime_error(ss.str());
}
} // namespace helpers
