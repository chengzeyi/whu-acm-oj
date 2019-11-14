#include <bits/stdc++.h>

size_t calcMostDistance(
        const std::vector<std::unordered_map<size_t, size_t>> &tree,
        size_t &maxCost,
        size_t start=0
        ) {
    std::queue<std::pair<size_t, size_t>> q;
    q.emplace(start, 0);
    std::vector<size_t> visited(tree.size());
    visited[start] = true;
    maxCost = 0;
    size_t result = start;
    while (!q.empty()) {
        auto &&children = tree.at(q.front().first);
        size_t totalCost = q.front().second;
        q.pop();
        for (auto &&edge : children) {
            size_t child = edge.first;
            if (visited[child]) {
                continue;
            }
            size_t cost = edge.second;
            size_t newTotalCost = totalCost + cost;
            if (newTotalCost > maxCost) {
                maxCost = newTotalCost;
                result = child;
            }
            visited[child] = true;
            q.emplace(child, newTotalCost);
        }
    }
    return result;
}

size_t calcMinDistance(
        const std::vector<std::unordered_map<size_t, size_t>> &tree,
        size_t sum
        ) {
    size_t maxCost;
    size_t a = calcMostDistance(tree, maxCost);
    calcMostDistance(tree, maxCost, a);
    return sum * 2 - maxCost;
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
2
1 2 3
3
1 2 3
1 3 4)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<std::unordered_map<size_t, size_t>> tree(n);
        size_t sum = 0;
        for (size_t j = 0; j < n - 1; ++j) {
            size_t u, v, d;
            std::cin >> u >> v >> d;
            u--;
            v--;
            sum += d;
            tree[u].emplace(v, d);
            tree[v].emplace(u, d);
        }
        std::cout << "Case " << i + 1 << ':' << std::endl;
        std::cout << calcMinDistance(tree, sum) << std::endl;
        if (i + 1 != t) {
            std::cout << std::endl;
        }
    }
    return 0;
}
