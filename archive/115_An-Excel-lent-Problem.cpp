#include <bits/stdc++.h>

std::string convert(std::string &raw) {
    for (auto &&c : raw) {
        if (c == 'R' || c == 'C') {
            c = ' ';
        }
    }
    std::stringstream ss;
    ss << raw;
    size_t row, col;
    ss >> row >> col;
    std::string result;
    while (col != 0) {
        result += col % 26;
        if (result.back() == 0) {
            result.back() = 26;
            --col;
        }
        result.back() += 'A' - 1;
        col /= 26;
    }
    std::reverse(result.begin(), result.end());
    result += std::to_string(row);
    return result;
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(R1C1
R3C1
R1C3
R299999999C26
R52C52
R53C17576
R53C17602
R0C0)";
#endif
    std::string s;
    while (true) {
        std::cin >> s;
        if (s == "R0C0") {
            break;
        }
        std::cout << convert(s) << std::endl;
    }
    return 0;
}
