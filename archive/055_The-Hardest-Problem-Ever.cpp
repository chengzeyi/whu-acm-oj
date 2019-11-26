#include <bits/stdc++.h>

std::string decipher(std::string &s) {
    for (auto &&c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + ('Z' - 'A' + 1 + c - 'A' - 5) % ('Z' - 'A' + 1);
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
    std::cin << R"(START
HTSLWFYZQFYNTSX, DTZ'A XTQAJI YMJ MFWIJXY UWTGQJR JAJW!
END
START
OZQNZX HFJXFW QNAJI NS F YNRJ TK IFSLJW FSI NSYWNLZJ.
END
START
YMJ MFWIJXY XNYZFYNTS HFJXFW JAJW KFHJI BFX PJJUNSL MNRXJQK FQNAJI.
END
ENDOFINPUT)";
#endif
    while (true) {
        std::string s;
        std::getline(std::cin, s);
        if (s == "ENDOFINPUT") {
            break;
        }
        if (s == "START") {
            std::getline(std::cin, s);
            std::cout << decipher(s) << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}
