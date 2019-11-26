#include <bits/stdc++.h>

std::string solve(const std::vector<std::pair<int, int>> &petals) {
    size_t n = petals.size();
    if (n <= 1) {
        return "YES";
    }
    std::vector<int> a(n), b(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (petals[j].first == petals[i].first) {
                a[i]++;
                b[i] += petals[j].second;
            }
        }
    }
    double avg = 1.0 * b[0] / a[0];
    for (size_t i = 1; i < n; ++i) {
        if (std::abs(a[i] * avg - b[i]) > 1e-5) {
            return "NO";
        }
    }
    return "YES";
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(5
0 0
2 0
1 1
0 2
2 2
4
0 0
2 0
1 1
0 2)";
#endif
    size_t n;
    while (std::cin >> n) {
        std::vector<std::pair<int, int>> petals(n);
        for (auto &&petal : petals) {
            std::cin >> petal.first >> petal.second;
        }
        std::cout << solve(petals) << std::endl;
    }
    return 0;
}
