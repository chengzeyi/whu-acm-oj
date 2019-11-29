#include <bits/stdc++.h>

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(6 4
3 2)";
#endif
    std::vector<std::vector<size_t>> dp(256, std::vector<size_t>(256, 1));
    for (size_t i = 2; i < 256; ++i) {
        for (size_t j = 2; j < 256; ++j) {
            if (i >= j) {
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][i];
            }
        }
    }
    size_t m, n;
    while (std::cin >> m >> n) {
        std::cout << dp[m][n] << std::endl;
    }
    return 0;
}
