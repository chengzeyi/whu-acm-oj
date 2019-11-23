#include <bits/stdc++.h>

size_t calcNumOfWays(size_t n) {
    size_t result = 1;
    if (n == 1) {
        return result;
    }
    for (size_t i = 1; i < n; ++i) {
        result += calcNumOfWays(i);
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
    std::cin << R"(1
2
3
0
)";
#endif
    while (true) {
        size_t n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::cout << calcNumOfWays(n) << std::endl;
    }
    return 0;
}
