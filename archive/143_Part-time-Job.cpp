#include <bits/stdc++.h>

size_t calcNumberOfDollars(size_t m, size_t p, size_t n) {
    return std::max(m, p * n);
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(20 5 3
20 5 5
0 0 0)";
#endif
    size_t m, p, n;
    while (true) {
        std::cin >> m >> p >> n;
        if ((m | p | n) == 0) {
            break;
        }
        std::cout << calcNumberOfDollars(m, p, n) << std::endl;
    }
    return 0;
}
