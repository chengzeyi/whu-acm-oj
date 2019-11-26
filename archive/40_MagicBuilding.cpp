#include <bits/stdc++.h>

size_t calcMinNumOfMagicBuildings(const std::vector<size_t> &buildings) {
    std::unordered_map<size_t, size_t> building2Count;
    for (auto &&building : buildings) {
        building2Count[building]++;
    }
    return std::max_element(building2Count.begin(), building2Count.end())->second;
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
1
2
5
1 2 2 3 3)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<size_t> buildings(n);
        for (size_t j = 0; j < n; ++j) {
            std::cin >> buildings[j];
        }
        std::cout << calcMinNumOfMagicBuildings(buildings) << std::endl;
    }
    return 0;
}
