#include <bits/stdc++.h>

std::vector<size_t> cache(1000 * 1000 + 1);

std::vector<size_t> halfCache(1000 * 1000 + 1);

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(13)";
#endif
    halfCache[0] = 0;
    halfCache[1] = 0;
    halfCache[2] = 1;
    halfCache[3] = 2;
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 5;
    for (size_t i = 4; i < 1000 * 1000 + 1; ++i) {
        halfCache[i] = (cache[i - 2] + halfCache[i - 1]) % 10000;
        cache[i] = (cache[i - 1] + cache[i - 2] + halfCache[i - 1] * 2) % 10000;
    }
    size_t n;
    while (std::cin >> n) {
        std::cout << cache[n] << std::endl;
    }
    return 0;
}
