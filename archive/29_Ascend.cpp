#include <bits/stdc++.h>

std::string decryptMsg(const std::string &encryptedMsg) {
    std::string result(encryptedMsg);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = ('Z' - 'A' + 1 + result[i] - 'A' - (i + 1) % ('Z' - 'A' + 1)) % ('Z' - 'A' + 1) + 'A';
    }
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
    std::cin << R"(XJX
BEPMHVJ
$)";
#endif
    while (true) {
        std::string encryptedMsg;
        std::cin >> encryptedMsg;
        if (encryptedMsg == "$") {
            break;
        }
        std::cout << decryptMsg(encryptedMsg) << std::endl;
    }
    return 0;
}
