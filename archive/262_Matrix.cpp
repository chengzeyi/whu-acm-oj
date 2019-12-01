#include <bits/stdc++.h>

struct Env {
    size_t n;
    size_t depth;
    std::vector<int> counts;
    Env(size_t n, size_t depth) {
        this->n = n;
        this->depth = depth;
        this->counts = std::vector<int>(n);
    }
};

int calcMinMax(const std::vector<std::vector<int>> &matrix, Env &env) {
    if (env.depth == env.n) {
        return *std::max_element(env.counts.begin(), env.counts.end());
    }
    int minMax = std::numeric_limits<int>::max();
    auto &line = matrix[env.depth];
    for (size_t i = 0; i < env.n; ++i) {
        for (size_t j = 0; j < env.n; ++j) {
            env.counts[j] += line[j + i];
        }
        ++env.depth;
        minMax = std::min(minMax, calcMinMax(matrix, env));
        --env.depth;
        for (size_t j = 0; j < env.n; ++j) {
            env.counts[j] -= line[j + i];
        }
    }
    return minMax;
}

size_t calcMinMax(const std::vector<std::vector<int>> &matrix) {
    size_t n = matrix.size();
    Env env(n, 0);
    std::vector<std::vector<int>> newMat(n, std::vector<int>(2 * n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            newMat[i][j] = matrix[i][j];
            newMat[i][j + n] = matrix[i][j];
        }
    }
    return calcMinMax(newMat, env);
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2
4 6
3 7
3
1 2 3
4 5 6
7 8 9
-1)";
#endif
    while (true) {
        int n;
        std::cin >> n;
        if (n == -1) {
            break;
        }
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        std::cout << calcMinMax(matrix) << std::endl;
    }
    return 0;
}
