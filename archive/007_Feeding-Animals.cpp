#include <bits/stdc++.h>

size_t calcMinimumTime(const std::vector<std::vector<size_t>> &matrix) {
    size_t colNum = matrix.front().size();
    std::vector<size_t> times(colNum, std::numeric_limits<size_t>::max()) ;
    for (auto &&line : matrix) {
        for (size_t i = 0; i < colNum; ++i) {
            if (line[i] < times[i]) {
                times[i] = line[i];
            }
        }
    }
    return std::accumulate(times.begin(), times.end(), 0);
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(3
10 20 30
20 15 20
2 10 8
4 8 30
3 8 10
50 70 10
20 30 40
10 30 20
2
10 20
20 15
2 10
4 8
3 8
50 70
20 30
10 30)";
#endif
    size_t n;
    while(std::cin >> n) {
        std::vector<std::vector<size_t>> matrix(8, std::vector<size_t>(n));
        for (size_t i = 0; i < 8; ++i) {
            for (size_t j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        std::cout << calcMinimumTime(matrix) << std::endl;
    }
    return 0;
}
