#include <bits/stdc++.h>

size_t calcMaxDollars(
        const std::vector<std::vector<size_t>> &board
        ) {
    std::vector<size_t> currs1(board.size()), currs2(board.size());
    for (auto &&line : board) {
        for (size_t i = 0; i < board.size(); ++i) {
            size_t left = i == 0 ? 0 : currs1[i - 1];
            size_t mid = currs1[i];
            size_t right = i == board.size() - 1 ? 0 : currs1[i + 1];
            currs2[i] = line[i] + std::max({left, mid, right});
        }
        currs1.swap(currs2);
    }
    return *std::max_element(currs1.begin(), currs1.end());
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
3
1 3 5
7 0 8
4 0 0)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<std::vector<size_t>> board(n, std::vector<size_t>(n));
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                std::cin >> board[j][k];
            }
        }
        std::cout << "Case " << i + 1 << ':' << std::endl;
        std::cout << calcMaxDollars(board) << std::endl;
        if (i != t - 1) {
            std::cout << std::endl;
        }
    }
    return 0;
}
