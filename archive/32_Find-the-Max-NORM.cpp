#include <bits/stdc++.h>

size_t findMaxNorm(
    const std::vector<std::vector<size_t>> &matrix,
    size_t depth,
    std::vector<size_t> &counts0,
    std::vector<size_t> &counts1
    ) {
    size_t m = matrix.size();
    size_t n = matrix.front().size();
    if (depth == m) {
        size_t oneCount = 0;
        for (size_t i = 0; i < n; ++i) {
            oneCount += std::max(counts0[i], counts1[i]);
        }
        return oneCount;
    }
    auto &line = matrix[depth];
    for (size_t i = 0; i < n; ++i) {
        size_t one = line[i];
        counts0[i] += !one;
        counts1[i] += one;
    }
    size_t count1 = findMaxNorm(matrix, depth + 1, counts0, counts1);
    for (size_t i = 0; i < n; ++i) {
        size_t one = line[i];
        counts0[i] = counts0[i] - !one + one;
        counts1[i] = counts1[i] - one + !one;
    }
    size_t count2 = findMaxNorm(matrix, depth + 1, counts0, counts1);
    for (size_t i = 0; i < n; ++i) {
        size_t one = line[i];
        counts0[i] -= one;
        counts1[i] -= !one;
    }
    return std::max(count1, count2);
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2 2
0 1
1 0
2 2
0 1
1 1)";
#endif
    size_t m, n;
    while (std::cin >> m >> n) {
        std::vector<std::vector<size_t>> matrix(m, std::vector<size_t>(n));
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                bool tmp;
                std::cin >> tmp;
                matrix[i][j] = tmp;
            }
        }
        std::vector<size_t> counts0(n), counts1(n);
        std::cout << findMaxNorm(matrix, 0, counts0, counts1) << std::endl;
    }
    return 0;
}
