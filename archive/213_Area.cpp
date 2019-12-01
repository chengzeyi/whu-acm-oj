#include <bits/stdc++.h>

size_t calcTotalArea(const std::vector<std::pair<size_t, size_t>> &vertices) {
    size_t n = vertices.size();
    size_t result = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        result += vertices[i].first * vertices[i + 1].second - vertices[i + 1].first * vertices[i].second;
    }
    result += vertices[n - 1].first * vertices[0].second - vertices[0].first * vertices[n - 1].second;
    result /= 2;
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
    std::cin << R"(10
0 0
4 0
4 1
3 1
3 3
2 3
2 2
1 2
1 3
0 3)";
#endif
    size_t n;
    std::cin >> n;
    std::vector<std::pair<size_t, size_t>> vertices(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> vertices[i].first >> vertices[i].second;
    }
    std::cout << calcTotalArea(vertices) << std::endl;
    return 0;
}
