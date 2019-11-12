#include <bits/stdc++.h>

size_t calcValidSum(size_t n) {
    if (n <= 3) {
        return 1;
    }
    size_t groupNum = n / 3;
    size_t result = 0;
    for (size_t i = 0; i < groupNum; ++i) {
        result += calcValidSum(3 * i + 2) * calcValidSum(n - 3 * (i + 1)) * [](size_t n, size_t k) -> auto {
            long long a = 1, b = 1;
            if (k > n - k) {
                k = n - k;
            }
            for (size_t i = 0; i < k; ++i) {
                a *= n - i;
            }
            for (size_t i = 0; i < k; ++i) {
                b *= i + 1;
            }
            return a / b;
        }(n-1, 3 * i + 2);

    }
    if (n % 3 == 2) {
        result += calcValidSum(n - 1);
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
    std::cin << R"(2
3
4
6
9)";
#endif
    size_t n;
    while(std::cin >> n) {
        std::cout << calcValidSum(n) << std::endl;
    }
    return 0;
}
