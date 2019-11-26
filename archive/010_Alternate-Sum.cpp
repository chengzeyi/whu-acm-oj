#include <bits/stdc++.h>

#define BOUND 2006

long long calcTotalValue(const std::vector<int> &q) {
    size_t n = q.size();
    if (n == 0) {
        return 0;
    }
    long long total = *std::max_element(q.begin(), q.end());
    for (size_t i = 0; i < n - 1; ++i) {
        total *= 2;
        if (total < 0) {
            total += BOUND;
        }
        total %= BOUND;
    }
    return (total >= 0) ? (total) : (total + BOUND);
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
-1
2
0 4
3
1 3 2
0)";
#endif
    size_t n;
    while(std::cin >> n) {
        if (n == 0) {
            break;
        }
        std::vector<int> q(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> q[i];
        }
        std::cout << calcTotalValue(q) << std::endl;
    }
    return 0;
}
