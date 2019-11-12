#include <bits/stdc++.h>

unsigned calcMaxPoint(const std::vector<std::pair<size_t, unsigned>> &animals, size_t arkSize) {
    std::vector<int> dp(arkSize + 1);
    for (size_t i = 0; i < animals.size(); ++i) {
        size_t size = animals[i].first;
        unsigned point = animals[i].second;
        for (size_t j = arkSize; j >= size; --j) {
            int newPoint = dp[j - size] + point;
            if (newPoint > dp[j]) {
                dp[j] = newPoint;
            }
        }
    }
    return dp.back();
}

#ifdef DEBUG
# define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2
10 20
20 30
30
3
10 20
30 30
20 20
30)";
#endif
    size_t n;
    std::vector<std::pair<size_t, unsigned>> animals;
    while (std::cin >> n) {
        animals.resize(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> animals[i].first >> animals[i].second;
        }
        size_t arkSize;
        std::cin >> arkSize;
        std::cout << calcMaxPoint(animals, arkSize) << std::endl;
    }
    return 0;
}
