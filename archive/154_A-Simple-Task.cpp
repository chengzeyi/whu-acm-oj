#include <bits/stdc++.h>

std::string getNewPassword(std::string &pwd) {
    size_t n = pwd.size();
    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            pwd[i] = std::toupper(pwd[i]);
        }
    }
    return pwd;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(abcdefg
alice
bob
#)";
#endif
    std::string pwd;
    size_t c = 0;
    while (true) {
        std::cin >> pwd;
        if (pwd == "#") {
            break;
        }
        ++c;
        std::cout << "Case " << c << ": " << getNewPassword(pwd) << std::endl;
    }
    return 0;
}
