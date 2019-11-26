#include <bits/stdc++.h>

size_t calcWhiteRectNum(const std::vector<std::string> &board) {
    if (board.empty() || board.front().empty()) {
        return 0;
    }
    size_t height = board.size();
    size_t width = board.front().size();

    std::vector<size_t> signs(width + 1), sum(width + 1), pre(width + 1);
    size_t count = 0;
    for (size_t i = 0; i < height; ++i) {
        auto &line = board[i];
        for (size_t j = 0; j < width; ++j) {
            if (line[j] == 'w') {
                signs[j + 1]++;
            } else {
                signs[j + 1] = 0;
            }
        }
        for (size_t j = 0; j < width; ++j) {
            if (signs[j] <= signs[j + 1]) {
                sum[j + 1] = sum[j] + signs[j + 1];
                pre[j + 1] = 0;
            } else {
                pre[j + 1] = pre[j] + 1;
                size_t p = j + 1 - pre[j + 1];
                while (p != 0 && signs[p - 1] >= signs[j + 1]) {
                    p = p - pre[p - 1] - 1;
                }
                if (p == 0) {
                    sum[j + 1] = signs[j + 1] * (j + 1);
                    pre[j + 1] = 0;
                } else {
                    sum[j + 1] = signs[j + 1] * (j + 2 - p) + sum[p - 1];
                    pre[j + 1] = j - p;
                }
            }
            count += sum[j + 1];
        }
    }
    return count;
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2 3
bbb
www
2 2
bw
wb)";
#endif
    size_t n, m;
    while(std::cin >> n >> m) {
        std::vector<std::string> board(n);
        for (size_t i = 0; i < n; ++i) {
            board[i].reserve(m);
            std::cin >> board[i];
        }
        std::cout << calcWhiteRectNum(board) << std::endl;
    }
    return 0;
}
