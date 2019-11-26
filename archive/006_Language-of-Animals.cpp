#include <bits/stdc++.h>

std::vector<int> solve(
    size_t n,
    const std::vector<std::pair<size_t, size_t>> &pairs,
    const std::vector<std::pair<size_t, size_t>> &queries
) {
    std::unordered_map<size_t, std::unordered_set<size_t>> graph;
    for (auto &&p : pairs) {
        size_t a = p.first, b = p.second;
        graph.emplace(a, std::unordered_set<size_t>()).first->second.insert(b);
        graph.emplace(b, std::unordered_set<size_t>()).first->second.insert(a);
    }
    std::vector<int> results;
    results.reserve(queries.size());
    for (auto &&query : queries) {
        size_t a = query.first, b = query.second;
        if (a == b) {
            results.push_back(0);
            continue;
        }
        size_t result = 0;
        std::unordered_set<size_t> visited({a});
        std::queue<size_t> quea({a}), queb;
        while (!quea.empty()) {
            while (!quea.empty()) {
                size_t curr = quea.front();
                quea.pop();
                auto it = graph.find(curr);
                if (it == graph.end()) {
                    continue;
                }
                for (size_t next : it->second) {
                    if (next == b) {
                        results.push_back(result);
                        goto END;
                    }
                    if (visited.find(next) != visited.end()) {
                        continue;
                    }
                    visited.insert(next);
                    queb.push(next);
                }
            }
            result++;
            quea.swap(queb);
        }
        results.push_back(-1);
        END:
        continue;
    }
    return results;
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(3 2
0 1
1 2
2
0 0
0 2)";
#endif
    size_t n, m, k;
    std::vector<std::pair<size_t, size_t>> pairs, queries;
    std::cin >> n >> m;
    pairs.reserve(m);
    for (size_t i = 0; i < m; ++i) {
        size_t a, b;
        std::cin >> a >> b;
        pairs.emplace_back(a, b);
    }
    std::cin >> k;
    queries.reserve(k);
    for (size_t i = 0; i < k; ++i) {
        size_t a, b;
        std::cin >> a >> b;
        queries.emplace_back(a, b);
    }
    auto results = solve(n, pairs, queries);
    for (int result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}
