#include <bits/stdc++.h>

size_t calcMinLength(const std::vector<std::vector<size_t>> &matrix) {
    size_t n = matrix.size();
    std::unordered_set<size_t> s;
    size_t result;
    {
        size_t minLength = std::numeric_limits<size_t>::max();
        size_t from, to;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i != j && matrix[i][j] < minLength) {
                    minLength = matrix[i][j];
                    from = i;
                    to = j;
                }
            }
        }
        result =  minLength;
        s.insert(from);
        s.insert(to);
    }
    for (size_t i = 0; i < n - 2; ++i) {
        size_t minLength = std::numeric_limits<size_t>::max();
        size_t to;
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                if (j != k && s.find(j) != s.end() && s.find(k) == s.end() && matrix[j][k] < minLength) {
                    minLength = matrix[j][k];
                    to = k;
                }
            }
        }
        result += minLength;
        s.insert(to);
    }
    return result;
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
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<std::vector<size_t>> matrix(n, std::vector<size_t>(n));
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                std::cin >> matrix[j][k];
            }
        }
        std::cout << calcMinLength(matrix) << std::endl;
    }
    return 0;
}
