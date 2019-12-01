#include <bits/stdc++.h>

void convert(std::vector<std::vector<size_t>> &img) {
    for (auto &&line : img) {
        for (auto &&pixel : line) {
            unsigned char byte = pixel;
            pixel = 0;
            for (size_t i = 0; i < 8; ++i) {
                if (byte & (1 << i)) {
                    pixel = !pixel;
                }
            }
        }
    }
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
1 2
3 4)";
#endif
    size_t n;
    while (std::cin >> n) {
        std::vector<std::vector<size_t>> img(n, std::vector<size_t>(n));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                std::cin >> img[i][j];
            }
        }
        convert(img);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                std::cout << img[i][j];
                if (j == n - 1) {
                    std::cout << std::endl;
                } else {
                    std::cout << ' ';
                }
            }
        }
    }
    return 0;
}
