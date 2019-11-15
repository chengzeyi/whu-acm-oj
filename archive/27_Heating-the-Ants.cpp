#include <bits/stdc++.h>

struct Ant {
    size_t pos;
    int dir;
};

std::vector<size_t>
calcAntPositions(
        std::vector<Ant> &ants,
        size_t l,
        size_t t
        ) {
    size_t n = ants.size();
    std::vector<std::pair<size_t, size_t>> initPosAndIndices(n);
    for (size_t i = 0; i < n; ++i) {
        initPosAndIndices[i] = { ants[i].pos, i };
    }
    std::sort(initPosAndIndices.begin(), initPosAndIndices.end(),
            [](const std::pair<size_t, size_t> &a, const std::pair<size_t, size_t> &b) {
                return a.first < b.first;
            });
    size_t offsetL = 0, offsetR = 0;
    for (auto &&ant : ants) {
        if (ant.dir == 1) {
            offsetR = (offsetR + (ant.pos + t) / l) % n;
            ant.pos = (ant.pos + t) % l;
        } else {
            offsetL = (offsetL + (t + l - 1 - ant.pos) / l) % n;
            ant.pos = (ant.pos + l - t % l) % l;
        }
    }
    size_t offset = (n + offsetR - offsetL) % n;
    std::sort(ants.begin(), ants.end(),
            [](const Ant &a, const Ant &b) { return a.pos < b.pos; });
    std::vector<size_t> results(n);
    for (size_t i = 0; i < n; ++i) {
        size_t idx = (i + offset) % n;
        results[initPosAndIndices[i].second] = ants[idx].pos;
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
    std::cin << R"(2
4 2 0
0 1
2 -1
4 2 1
0 1
2 -1)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t l, n, dur;
        std::cin >> l >> n >> dur;
        std::vector<Ant> ants(n);
        for (size_t j = 0; j < n; ++j) {
            std::cin >> ants[j].pos >> ants[j].dir;
        }
        std::cout << "Case " << i + 1 << ':' << std::endl;
        auto results = calcAntPositions(ants, l, dur);
        for (size_t j = 0; j < n; ++j) {
            std::cout << results[j];
            if (j == n - 1) {
                std::cout << std::endl;
            } else {
                std::cout << ' ';
            }
        }
        if (i != t - 1) {
            std::cout << std::endl;
        }
    }
    return 0;
}
