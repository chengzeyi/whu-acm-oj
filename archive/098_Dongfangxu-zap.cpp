#include <bits/stdc++.h>

std::string playGame(const std::string &s) {
    size_t dcount = 0, zcount = 0;
    size_t tdcount = 0, tzcount = 0;
    std::string dname = "dongfangxu", zname = "zap";
    for (auto it = s.begin(); it != s.end();) {
        if (*it == 'd' || *it == 'z') {
            std::string &name = *it == 'd' ? dname : zname;
            auto itn = name.begin();
            while (it != s.end() && itn != name.end() && *it == *itn) {
                ++it;
                ++itn;
            }
            if (itn == name.end()) {
                if (name[0] == 'd') {
                    ++tdcount;
                    if (tdcount > dcount) {
                        dcount = tdcount;
                    }
                    tzcount = 0;
                } else {
                    ++tzcount;
                    if (tzcount > zcount) {
                        zcount = tzcount;
                    }
                    tdcount = 0;
                }
            } else {
                tdcount = 0;
                tzcount = 0;
            }
        } else {
            tdcount = 0;
            tzcount = 0;
            ++it;
        }
    }
    return dcount >= zcount ? "dongfangxu!" : "zap!";
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
dongfaxuzapzap)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        std::string s;
        std::cin >> s;
        std::cout << playGame(s) << std::endl;
    }
    return 0;
}
