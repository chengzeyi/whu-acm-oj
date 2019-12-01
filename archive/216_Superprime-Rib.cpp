#include <bits/stdc++.h>

bool isPrime(size_t n) {
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (size_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<size_t> getAllSuperPrimes(size_t n) {
    if (n == 1) {
        return std::vector<size_t>({2, 3, 5, 7});
    }
    std::vector<size_t> pre = getAllSuperPrimes(n - 1);
    std::vector<size_t> result;
    for (auto &&prime : pre) {
        for (size_t i = 1; i <= 9; i += 2) {
            size_t num = prime * 10 + i;
            if (isPrime(num)) {
                result.push_back(num);
            }
        }
    }
    return result;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(4)";
#endif
    size_t n;
    while (std::cin >> n) {
        auto result = getAllSuperPrimes(n);
        for (auto &&prime : result) {
            std::cout << prime << std::endl;
        }
    }
    return 0;
}
