#include <bits/stdc++.h>

void datePlusDays(std::tm &date, size_t days) {
    std::time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    std::time_t date_seconds = std::mktime(&date) + (days * ONE_DAY);

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    date = *localtime(&date_seconds);
}

std::string format(size_t offset) {
    std::tm t = {};
    std::stringstream ss("2000-01-01");
    ss >> std::get_time(&t, "%y-%m-%d");
    datePlusDays(t, offset);
    ss.clear();
    ss << std::put_time(&t, "%Y-%m-%d %A");
    return ss.str();
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(1730
1740
1750
1751
-1)";
#endif
    while (true) {
        int offset;
        std::cin >> offset;
        if (offset == -1) {
            break;
        }
        std::cout << format(offset) << std::endl;
    }
    return 0;
}
