#ifndef HASHCOMBINE_HPP
#define HASHCOMBINE_HPP
#include <vector>

namespace Utils {
    template<class T>
    using Vec = std::vector<T>;

    template<class T>
    class VectorHash {
    public:
        uint operator()(Vec<T> const &vec) const {
            std::size_t seed = vec.size();
            for (auto &i: vec) {
                seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
}


#endif //HASHCOMBINE_HPP