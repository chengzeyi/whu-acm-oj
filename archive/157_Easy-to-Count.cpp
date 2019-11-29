#include <bits/stdc++.h>

size_t countNumberOfCollisions(const std::vector<int> &boxes) {
    size_t before = 0, total = 0;
    for (auto &&box : boxes) {
        if (box == 1) {
            before += 1;
        } else {
            total += before;
        }
    }
    return total;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(3
1 -1 1
4
1 -1 1 -1
-1)";
#endif
    size_t n;
    size_t c = 0;
    while (true) {
        std::cin >> n;
        if (n == -1) {
            break;
        }
        ++c;
        std::vector<int> boxes(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> boxes[i];
        }
        std::cout << "Case " << c << ": " << countNumberOfCollisions(boxes) << std::endl;
    }
    return 0;
}
