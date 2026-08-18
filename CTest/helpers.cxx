#include <helpers.hxx>

namespace helpers {
auto checkeqDict(const std::unordered_map<std::string, std::string>& lhs,
                 const std::unordered_map<std::string, std::string>& rhs)
    -> void {
    if (lhs.size() != rhs.size()) {
        std::stringstream ss;
        ss << "Sizes not equals:" << std::endl
           << "  1. " << lhs.size() << std::endl
           << "  2. " << rhs.size() << std::endl;

        throw std::runtime_error(ss.str());
    }

    for (const auto& [k, v] : lhs) {
        if (const auto it {rhs.find(k)}; it != rhs.end()) {
            if (v != it->second) {
                std::stringstream ss;
                ss << "Values not equals:" << std::endl
                   << "  1. " << v << std::endl
                   << "  2. " << it->second << std::endl;

                throw std::runtime_error(ss.str());
            }
        } else
            throw std::runtime_error("Key not found:\n  " + k);
    }
}
} // namespace helpers
