#include <bits/stdc++.h>

int calcMinDistance(size_t n, std::pair<size_t, size_t> init, std::pair<size_t, size_t> fin) {
    size_t vertDistance = std::max(init.first, fin.first) - std::min(init.first, fin.first);
    size_t horiDistance = std::max(init.second, fin.second) - std::min(init.second, fin.second);
    if (vertDistance % 2 != horiDistance %2) {
        return -1;
    }
    return std::max(vertDistance, horiDistance);
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2
4
1 1
2 2
8
3 3
3 3)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::pair<size_t, size_t> init, fin;
        std::cin >> init.first >> init.second;
        std::cin >> fin.first >> fin.second;
        std::cout << "Case " << i + 1 << ':' << std::endl;
        std::cout << calcMinDistance(n, init, fin) << std::endl;
        if (i != t - 1) {
            std::cout << std::endl;
        }
    }
    return 0;
}
