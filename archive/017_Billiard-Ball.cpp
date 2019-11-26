#include <bits/stdc++.h>

double sqrtPowered(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return std::sqrt(std::pow(a.first - b.first, 2.0) + std::pow(a.second - b.second, 2.0));
}

double calcShortestTraj(const std::vector<std::pair<int, int>> &vertices) {
    double a = sqrtPowered(vertices[0], vertices[1]);
    double b = sqrtPowered(vertices[0], vertices[2]);
    double c = sqrtPowered(vertices[1], vertices[2]);
    double cosA = (b * b + c * c - a * a) / (2.0 * b * c);
    return 2.0 * b * c * (1 - cosA * cosA) / a;
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
0 0 2 0 1 2
0 0 2 0 1 3)";
#endif
    size_t n;
    std::vector<std::pair<int, int>> vertices(3);
    std::cin >> n;
    while (n--) {
        std::cin >> vertices[0].first >> vertices[0].second >>
            vertices[1].first >> vertices[1].second >>
            vertices[2].first >> vertices[2].second;
        std::cout << std::fixed << std::setprecision(3) << calcShortestTraj(vertices) << std::endl;
    }
    return 0;
}
