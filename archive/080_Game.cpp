#include <bits/stdc++.h>

std::string playGame(size_t n) {
    n = (n - 1) % 14 + 1;
    if (n <= 13) {
        return "flymouse wins the game!";
    }
    return  "snoopy wins the game!";
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
9
14)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::cout << playGame(n) << std::endl;
    }
    return 0;
}
