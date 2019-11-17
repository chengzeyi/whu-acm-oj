#include <bits/stdc++.h>

size_t calcLargestNumOfPieces(size_t n) {
    return (n * n * n + 5 * n + 6) / 6;
}

#ifdef DEBUG
#define cin _ss
namespace std{
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(1
2
3)";
#endif
    size_t n;
    while (std::cin >> n) {
        std::cout << calcLargestNumOfPieces(n) << std::endl;
    }
    return 0;
}
