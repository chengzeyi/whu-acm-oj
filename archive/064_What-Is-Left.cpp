#include <bits/stdc++.h>

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(5
1 2 5 4 5
2
1 2)";
#endif
    size_t n;
    while (std::cin >> n) {
        std::set<size_t> s;
        for (size_t i = 0; i < n; ++i) {
            size_t t;
            std::cin >> t;
            s.insert(t);
        }
        bool first = true;
        for (auto &&e : s) {
            if (first) {
                first = false;
            } else {
                std::cout << ' ';
            }
            std::cout << e;
        }
        std::cout << std::endl;
    }
    return 0;
}
