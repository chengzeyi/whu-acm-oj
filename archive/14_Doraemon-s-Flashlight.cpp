#include <bits/stdc++.h>

std::vector<std::vector<int>> vertices({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        });

std::vector<int> multiply(const std::vector<std::vector<int>> &matrix, const std::vector<int> &vertex) {
    std::vector<int> result(3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            result[i] += matrix[i][j] * vertex[j];
        }
    }
    return result;
}

int calcVolume(const std::vector<std::vector<int>> &matrix) {
    std::vector<std::vector<int>> convertedVertices;
    for (auto &&vertex : vertices) {
        convertedVertices.push_back(multiply(matrix, vertex));
    }
    return std::abs(
            matrix[0][0] * matrix[1][1] * matrix[2][2] +
            matrix[1][0] * matrix[2][1] * matrix[0][2] +
            matrix[2][0] * matrix[1][2] * matrix[0][1] -
            matrix[2][0] * matrix[1][1] * matrix[0][2] -
            matrix[0][1] * matrix[1][0] * matrix[2][2] -
            matrix[0][0] * matrix[2][1] * matrix[1][2]
            );
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(1 0 1
0 2 0
-1 0 1

1 0 0
0 1 0
0 0 1)";
#endif
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));
    while (true) {
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                if (!(std::cin >> matrix[i][j])) {
                    return 0;
                }
            }
        }
        std::cout << calcVolume(matrix) << ".00" << std::endl;
    }
    return 0;
}
