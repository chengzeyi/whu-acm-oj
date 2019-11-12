#include <bits/stdc++.h>

std::vector<int> sortAdjDiff(const std::vector<int> &sequence) {
    std::vector<int> results(sequence.size());
    results[0] = sequence[0];
    for (size_t i = 0; i < sequence.size() - 1; ++i) {
        results[i + 1]  = sequence[i + 1] - sequence[i];
    }
    std::sort(results.begin(), results.end());
    return results;
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
5
1 3 2 4 5)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<int> sequence(n);
        for (size_t j = 0; j < n; ++j) {
            std::cin >> sequence[j];
        }
        std::vector<int> results = sortAdjDiff(sequence);
        std::cout << "Case " << i + 1 << ':' << std::endl;
        for (size_t j = 0; j < n; ++j) {
            std::cout << results[j];
            if (j + 1 == n) {
                std::cout << std::endl;
            } else {
                std::cout << ' ';
            }
        }
        if (i + 1 < t) {
            std::cout << std::endl;
        }
    }
    return 0;
}
