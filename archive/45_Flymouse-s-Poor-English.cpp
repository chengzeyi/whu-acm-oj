#include <bits/stdc++.h>

std::string correctSentence(std::string &s) {
    bool start = true, letter = false;
    for (auto &&c : s) {
        if (std::isalnum(c)) {
            if (start) {
                if (std::isalpha(c)) {
                    c = std::toupper(c);
                }
                start = false;
            } else if (std::isalpha(c) && letter) {
                    c = std::tolower(c);
            }
            letter = true;
        } else {
            letter = false;
        }
    }
    return s;
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
flymouse is poor in EnGlish but his girlfriend is good at English
)";
#endif
    size_t t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (size_t i = 0; i < t; ++i) {
        std::string s;
        std::getline(std::cin, s);
        std::cout << correctSentence(s) << std::endl;
    }
    return 0;
}
