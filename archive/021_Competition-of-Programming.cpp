#include <bits/stdc++.h>

size_t calcMinPenalty(std::vector<std::pair<size_t, size_t>> &problems) {
    if (problems.empty()) {
        return 0;
    }
    auto compByTime = [](const std::pair<size_t, size_t> &l, const std::pair<size_t, size_t> &r) -> auto {
        return l.first < r.first;
    };
    std::sort(problems.begin(), problems.end(), compByTime);

    auto compByPenalty = [](const std::pair<size_t, size_t> &l, const std::pair<size_t, size_t> &r) -> auto {
        return l.second < r.second;
    };
    std::vector<std::pair<size_t, size_t>> heap;

    size_t lastTime = problems.back().first;
    while (lastTime != 0) {
        while (!problems.empty() && problems.back().first == lastTime) {
            heap.push_back(problems.back());
            std::push_heap(heap.begin(), heap.end(), compByPenalty);
            problems.pop_back();
        }
        while (lastTime != 0) {
            if (!heap.empty()) {
                std::pop_heap(heap.begin(), heap.end(), compByPenalty);
                heap.pop_back();
            }
            lastTime--;
            if (!problems.empty() && problems.back().first == lastTime) {
                break;
            }
        }
    }

    size_t totalPenalty = 0;
    for (auto &&problem : heap) {
        totalPenalty += problem.second;
    }

    return totalPenalty;
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
3
1 5
3 2
3 4
3
1 5
2 2
2 4)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<std::pair<size_t, size_t>> problems(n);
        for (size_t j = 0; j < n; ++j) {
            std::cin >> problems[j].first >> problems[j].second;
        }
        std::cout << "Case " << i + 1 << ':' << std::endl;
        std::cout << calcMinPenalty(problems) << std::endl;
        if (i + 1 != t) {
            std::cout << std::endl;
        }
    }
    return 0;
}
