#include <bits/stdc++.h>

size_t calcHowLong(size_t n, size_t k) {
    if (n >= k) {
        return n - k;
    }
    std::unordered_set<size_t> s1({n}), s2, visited;
    size_t count = 0;
    while (true) {
        for (size_t pos : s1) {
            if (pos == k) {
                goto END;
            }
            if (visited.find(pos) != visited.end()) {
                continue;
            }
            visited.insert(pos);
            if (pos != 0) {
                s2.insert(pos - 1);
            }
            if (pos < k) {
                s2.insert(pos + 1);
            }
            if (pos * 2 < k * 2) {
                s2.insert(pos * 2);
            }
        }
        s1.clear();
        s1.swap(s2);
        ++count;
    }
END:
    return count;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(5 17)";
#endif
    size_t n, k;
    while (std::cin >> n >> k) {
        std::cout << calcHowLong(n, k) << std::endl;
    }
    return 0;
}
