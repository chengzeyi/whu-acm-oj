#include <bits/stdc++.h>

struct Status {
    size_t line;
    size_t col;
    size_t dir;
    size_t bite;

    Status(size_t line, size_t col, size_t bite) {
        this->line = line;
        this->col = col;
        this->bite = bite;
        dir = 0;
    }
};

std::string canFindAmaze(const std::vector<std::string> &forest) {
    size_t n = forest.size();
    std::pair<size_t, size_t> pigPos(std::numeric_limits<size_t>::max(), 0);
    std::pair<size_t, size_t> amazePos(std::numeric_limits<size_t>::max(), 0);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            char c = forest[i][j];
            if (c == 'p') {
                pigPos = {i, j};
            } else if (c == 'a') {
                amazePos = {i, j};
            }
        }
    }
    if (pigPos.first == std::numeric_limits<size_t>::max() ||
        amazePos.first == std::numeric_limits<size_t>::max()) {
        return "No";
    }
    std::vector<std::vector<bool>> visitedBite0(n, std::vector<bool>(n)),
        visitedBite1(n, std::vector<bool>(n));
    std::stack<Status> tasks({Status(pigPos.first, pigPos.second, 0)});
    while (!tasks.empty()) {
        auto &status = tasks.top();
        if (status.dir == 4) {
            tasks.pop();
            continue;
        }
        if (status.dir == 0) {
            if (visitedBite0[status.line][status.col] ||
                (status.bite == 1 && visitedBite1[status.line][status.col])) {
                tasks.pop();
                continue;
            }
            if (status.bite == 0) {
                visitedBite0[status.line][status.col] = true;
            } else {
                visitedBite1[status.line][status.col] = true;
            }
            switch (forest[status.line][status.col]) {
            case 'a':
                return "Yes";
            case 'k':
                tasks.pop();
                continue;
            case 'd':
                if (status.bite == 0) {
                    ++status.bite;
                    break;
                } else {
                    continue;
                }
            default:
                break;
            }
        }
        if (status.dir == 0) {
            ++status.dir;
            if (status.col != n - 1) {
                tasks.emplace(status.line, status.col + 1, status.bite);
                continue;
            }
        }
        if (status.dir == 1) {
            ++status.dir;
            if (status.line != n - 1) {
                tasks.emplace(status.line + 1, status.col, status.bite);
                continue;
            }
        }
        if (status.dir == 2) {
            ++status.dir;
            if (status.col != 0) {
                tasks.emplace(status.line, status.col - 1, status.bite);
                continue;
            }
        }
        if (status.dir == 3) {
            ++status.dir;
            if (status.line != 0) {
                tasks.emplace(status.line - 1, status.col, status.bite);
            }
        }
    }
    return "No";
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(4
3
pkk
rrd
rda
3
prr
kkk
rra
4
prrr
rrrr
rrrr
arrr
5
prrrr
ddddd
ddddd
rrrrr
rrrra)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<std::string> forest(n);
        for (size_t j = 0; j < n; ++j) {
            std::cin >> forest[j];
        }
        std::cout << canFindAmaze(forest) << std::endl;
    }
    return 0;
}
