#include <bits/stdc++.h>

size_t calcNumOfEmptySlots(size_t f, const std::vector<std::pair<size_t, size_t>> &flowers) {
    std::vector<bool> fence(f);
    for (auto &&flower : flowers) {
        size_t start = flower.first;
        size_t interval = flower.second;
        for (size_t i = start - 1; i < f; i += interval) {
            fence[i] = true;
        }
    }
    size_t count = 0;
    for (auto &&slot : fence) {
        count += !slot;
    }
    return count;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(30 3
1 3
3 7
1 4)";
#endif
    size_t f, k;
    std::cin >> f >> k;
    std::vector<std::pair<size_t, size_t>> flowers(k);
    for (size_t i = 0; i < k; ++i) {
        std::cin >> flowers[i].first >> flowers[i].second;
    }
    std::cout << calcNumOfEmptySlots(f, flowers) << std::endl;
    return 0;
}
