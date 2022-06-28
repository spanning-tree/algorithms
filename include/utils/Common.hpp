#ifndef ALGORITHMS_COMMON_HPP
#define ALGORITHMS_COMMON_HPP

#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <optional>
#include "utils/HashCombine.hpp"

namespace Utils {
    template<class T>
    using Vec = std::vector<T>;

    template<class T>
    using PriorityQueue = std::priority_queue<T>;

    template<class T>
    using Queue = std::queue<T>;

    template<class T>
    using Stack = std::stack<T>;

    template<class T1, class T2, class Hash>
    using HashMap = std::unordered_map<T1, T2, Hash>;

    template<class T>
    using Option = std::optional<T>;

    using std::nullopt;
    using uint = unsigned int;

}
#endif //ALGORITHMS_COMMON_HPP