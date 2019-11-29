#include <bits/stdc++.h>

void block(size_t i, size_t j, std::vector<std::string> &graph) {
    if (i >= graph.size() || j >= graph.front().size()) {
        return;
    }
    if (graph[i][j] == 'X') {
        return;
    }
    graph[i][j] = 'X';
    block(i - 1, j, graph);
    block(i - 1, j - 1, graph);
    block(i - 1, j + 1, graph);
    block(i + 1, j, graph);
    block(i + 1, j - 1, graph);
    block(i + 1, j + 1, graph);
    block(i, j - 1, graph);
    block(i, j + 1, graph);
}

size_t calcNumOfOilSite(std::vector<std::string> &graph) {
    size_t h = graph.size(), w = graph.front().size();
    size_t count = 0;
    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < w; ++j) {
            if (graph[i][j] == 'X') {
                continue;
            }
            ++count;
            block(i, j, graph);
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
    std::cin << R"(1 10
XXOOXOXOOO
3 3
OXO
XOX
OXO
0 0)";
#endif
    size_t r, c;
    while (true) {
        std::cin >> r >> c;
        if ((r | c) == 0) {
            break;
        }
        std::vector<std::string> graph(r);
        for (size_t i = 0; i < r; ++i) {
            std::cin >> graph[i];
        }
        std::cout << calcNumOfOilSite(graph) << std::endl;
    }
    return 0;
}
