#include <bits/stdc++.h>

std::string canComplete(
        const std::vector<int> &cs,
        const std::vector<int> &ds
        ) {
    return std::accumulate(cs.begin(), cs.end(), 0) >=
        std::accumulate(ds.begin(), ds.end(), 0) ?
        "YES" : "NO";
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(4
1 1 5 3
2 1 3 3
4
1 2 2 3
2 1 3 3
0)";
#endif
    while (true) {
        size_t n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::vector<int> cs(n), ds(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> cs [i];
        }
        for (size_t i = 0; i < n; ++i) {
            std::cin >> ds [i];
        }
        std::cout << canComplete(cs, ds) << std::endl;
    }
    return 0;
}
