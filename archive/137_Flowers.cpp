#include <bits/stdc++.h>

size_t calcMostFlowers(size_t m, const std::vector<size_t> &prices) {
    return m / *std::min_element(prices.begin(), prices.end());
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2 5
2 3)";
#endif
    while (true) {
        size_t n, m;
        if (!(std::cin >> n >> m)) {
            break;
        }
        std::vector<size_t> prices(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> prices[i];
        }
        std::cout << calcMostFlowers(m, prices) << std::endl;
    }
    return 0;
}
