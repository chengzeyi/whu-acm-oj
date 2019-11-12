#include <bits/stdc++.h>

struct Road {
    size_t to;
    size_t pguard;
    size_t sguard;
    size_t cost;
    char letter;
};

bool operator<(const Road &a, const Road &b) {
    return a.to < b.to;
}

void calcElixirsInner(
    size_t plovers,
    size_t slovers,
    size_t n,
    size_t curr,
    size_t currCost,
    const std::vector<std::set<Road>> &graph,
    std::vector<bool> &visited,
    std::string &elixirs,
    size_t &minCost,
    std::string &result
) {
    if (visited[curr] || currCost >= minCost) {
        return;
    }
    if (curr + 1 == n) {
        minCost = currCost;
        result = elixirs;
        return;
    }
    visited[curr] = true;
    for (auto &&road : graph[curr]) {
        if (plovers <= road.pguard || slovers <= road.sguard) {
            continue;
        }
        size_t newCost = currCost + road.cost;
        elixirs.push_back(road.letter);
        calcElixirsInner(plovers, slovers, n, road.to, newCost, graph, visited, elixirs, minCost, result);
        elixirs.pop_back();
    }
    visited[curr] = false;
}

std::string calcElixirs(
    size_t plovers,
    size_t slovers,
    size_t n,
    const std::vector<std::set<Road>> &graph
) {
    std::vector<bool> visited(n);
    std::string elixirs, result;
    size_t minCost = std::numeric_limits<size_t>::max();
    calcElixirsInner(plovers, slovers, n, 0, 0, graph, visited, elixirs, minCost, result);
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
    std::cin << R"(5 5
0 1 10 10 10 L
0 2 20 14 10 A
1 2 10 10 20 o
2 3 10 10 10 V
3 4 5 30 10 E
14 35)";
#endif
    size_t n, m;
    while(std::cin >> n >> m) {
        std::vector<std::set<Road>> graph(n);
        for (size_t i = 0; i < m; ++i) {
            size_t u, v;
            Road road;
            std::cin >> u >> v >> road.pguard >> road.sguard >> road.cost >> road.letter;
            road.to = v;
            graph[u].insert(road);
            road.to = u;
            graph[v].insert(road);
        }
        size_t plovers, slovers;
        std::cin >> plovers >> slovers;
        std::cout << calcElixirs(plovers, slovers, n, graph) << std::endl;
    }
    return 0;
}
