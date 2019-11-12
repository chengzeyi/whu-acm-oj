#include <bits/stdc++.h>

std::string calcFirstString(const std::string &bracelet) {
    size_t size = bracelet.size();
    std::list<size_t> watches(size);
    size_t i = 0;
    for (auto &&watch : watches) {
        watch = i++;
    }
    size_t round = 0;
    while (round < size && watches.size() > 1) {
        std::vector<char> chars(watches.size());
        auto it = watches.begin();
        std::for_each(chars.begin(), chars.end(), [&](char &ch) { ch = bracelet[*it++]; });
        char minCh = *std::min_element(chars.begin(), chars.end());
        watches.erase(std::remove_if(watches.begin(), watches.end(), [&](size_t &idx) -> auto { return bracelet[idx] != minCh; }), watches.end());
        for (auto &&idx : watches) {
            if (idx + 1 == size) {
                idx = 0;
            } else {
                idx++;
            }
        }
        round++;
    }
    size_t startIdx = (watches.front() + size - round) % size;
    return bracelet.substr(startIdx) + bracelet.substr(0, startIdx);
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(acabdb
kkisverystupid)";
#endif
    std::string bracelet;
    while (std::cin >> bracelet) {
        std::cout << calcFirstString(bracelet) << std::endl;
    }
    return 0;
}
