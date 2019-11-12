#include <bits/stdc++.h>

bool determineInner(
    const std::vector<std::vector<bool>> &matrix,
    size_t lineNum,
    size_t colNum,
    size_t col,
    std::vector<size_t> &person2Count
) {
    if (col == colNum) {
        return true;
    }
    for (size_t i = 0; i < lineNum; ++i) {
        if (matrix[i][col] && person2Count[i] != 0) {
            person2Count[i]--;
            if (determineInner(matrix, lineNum, colNum, col + 1, person2Count)) {
                return true;
            }
            person2Count[i]++;
        }
    }
    return false;
}

std::string determine(const std::vector<std::vector<bool>> &matrix, size_t k) {
    if (matrix.size() == 0 || matrix.front().size() == 0) {
        return "No";
    }
    size_t lineNum = matrix.size(), colNum = matrix.front().size();
    if (k * lineNum < colNum) {
        return "No";
    }
    std::vector<size_t> person2Count(lineNum, k);
    return determineInner(matrix, lineNum, colNum, 0, person2Count) ? "Yes" : "No";
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2 8
1 1 0 1 0 0 1 1
1 1 1 0 1 1 1 1
2
7 2
1 1
1 1
1 1
1 1
1 1
1 1
1 1
2)";
#endif
    size_t m, n;
    while(std::cin >> m >> n) {
        std::vector<std::vector<bool>> matrix(m, std::vector<bool>(n));
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                size_t tmp;
                std::cin >> tmp;
                matrix[i][j] = tmp ? true : false;
            }
        }
        size_t k;
        std::cin >> k;
        std::cout << determine(matrix, k) << std::endl;
    }
    return 0;
}
