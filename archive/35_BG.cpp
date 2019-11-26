#include <bits/stdc++.h>

size_t calcBG(size_t n) {
    return n / 2 + n % 2;
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
5
10
13
0)";
#endif
    while (true) {
        size_t n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::cout << calcBG(n) << std::endl;
    }
    return 0;
}
