#include <bits/stdc++.h>

std::string solve(const std::string &s) {
    std::unordered_map<std::string, size_t> name2Count({{"littleken", 0},
                                                        {"knuthocean", 0},
                                                        {"dongfangxu", 0},
                                                        {"zap", 0},
                                                        {"kittig", 0},
                                                        {"robertcui", 0},
                                                        {"forest", 0},
                                                        {"flirly", 0}});
    for (auto &&p : name2Count) {
        const std::string &name = p.first;
        size_t &count = p.second;
        for (auto it = s.begin(); it != s.end();) {
            if (*it == name[0]) {
                auto itn = name.begin();
                while (it != s.end() && itn != name.end() && *it == *itn) {
                    ++it;
                    ++itn;
                }
                if (itn == name.end()) {
                    ++count;
                }
            } else {
                ++it;
            }
        }
    }
    return std::max_element(name2Count.begin(), name2Count.end(),
                            [](const std::pair<std::string, size_t> &a,
                               const std::pair<std::string, size_t> &b) {
                                return a.second < b.second;
                            })
        ->first;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(1
zap)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        std::string s;
        std::cin >> s;
        std::cout << solve(s) << std::endl;
    }
    return 0;
}
