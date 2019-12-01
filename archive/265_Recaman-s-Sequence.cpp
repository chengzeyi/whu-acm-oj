#include <bits/stdc++.h>

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(7
10000
-1)";
#endif
    std::vector<size_t> as(500 * 1000 + 1);
    std::unordered_set<size_t> s;
    for (size_t i = 0; i < 500 * 1000; ++i) {
        size_t m = i + 1;
        if (as[i] > m && s.find(as[i] - m) == s.end()) {
            as[m] = as[i] - m;
        } else {
            as[m] = as[i] + m;
        }
        s.insert(as[m]);
    }
    while (true) {
        int k;
        std::cin >> k;
        if (k == -1) {
            break;
        }
        std::cout << as[k] << std::endl;
    }
    return 0;
}
