#include <bits/stdc++.h>

__uint128_t calcNumOfWaysInner(size_t n, size_t m, size_t k, std::vector<std::vector<__uint128_t>> &cache) {
    if (m == 1) {
        if (n <= k) {
            return 1;
        } else {
            return 0;
        }
    }
    if (2 * n > m * (m + 1) * k) {
        return 0;
    }
    __uint128_t &cached = cache[n][m];
    if (cached != 0) {
        return cached;
    }
    __uint128_t total = 0;
    for (size_t i = 0; i <= k && i * m <= n; ++i) {
        total += calcNumOfWaysInner(n - i * m, m - 1, k, cache);
    }
    cached = total;
    return total;
}

__uint128_t calcNumOfWays(size_t n, size_t m, size_t k) {
    if (2 * n > m * (m + 1) * k) {
        return 0;
    }
    std::vector<std::vector<__uint128_t>> cache(n + 1, std::vector<__uint128_t>(m + 1));
    return calcNumOfWaysInner(n, m, k, cache);
}

std::string toString(__uint128_t num) {
    std::string str;
    do {
        int digit = num % 10;
        str = std::to_string(digit) + str;
        num = (num - digit) / 10;
    } while (num != 0);
    return str;
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(1 1 1
4 2 2
5 3 2
0 0 0)";
#endif
    while (true) {
        size_t n, m, k;
        std::cin >> n >> m >> k;
        if ((n | m | k) == 0) {
            break;
        }
        std::cout << toString(calcNumOfWays(n, m, k)) << std::endl;
    }
    return 0;
}
