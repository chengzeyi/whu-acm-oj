#include <bits/stdc++.h>

void printDelimiter() {
    std::cout << "+-----+";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << "-----------+";
    }
    std::cout << std::endl;
}

void printSlogan(const std::string &slogan) {
    size_t spaceNum = 5 + 11 * 5 + 5;
    size_t s = slogan.size();
    size_t spaceL = (spaceNum - s) / 2 - 3;
    size_t spaceR = spaceL + 6;
    std::cout << "|" << std::string(spaceL, ' ') << slogan << std::string(spaceR, ' ') << "|" << std::endl;
}

void printLine(const std::vector<std::string> &courses, int day=-1) {
    if (day <= 0) {
        std::cout << "|     |";
    } else {
        std::cout << "|  " << day << "  |";
    }
    for (auto &&course : courses) {
        size_t s = course.size();
        size_t spaceL = (11 - s) / 2;
        size_t spaceR = spaceL;
        if (s % 2 == 0) {
            spaceR += 1;
        }
        std::string content = std::string(spaceL, ' ') + course + std::string(spaceR, ' ');
        std::cout << content << "|";
    }
    std::cout << std::endl;
}

void printHeader() {
    std::vector<std::string> workingDays({
            "MON", "TUE", "WED", "THU", "FRI"
            });
    printLine(workingDays);
}

void printTable(
    const std::vector<std::vector<std::string>> &morningCourses,
    const std::vector<std::vector<std::string>> &afternoonCourses
) {
    printDelimiter();
    printHeader();
    printDelimiter();
    printSlogan("Morning");
    printDelimiter();
    for (size_t i = 0; i < 4; ++i) {
        printLine(morningCourses[i], i + 1);
        printDelimiter();
    }
    printSlogan("Afternoon");
    printDelimiter();
    for (size_t i = 0; i < 3; ++i) {
        printLine(afternoonCourses[i], i + 1);
        printDelimiter();
    }
    std::cout << std::endl;
}

#ifdef DEBUG
#define cin _ss
namespace std {
    stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(4
Algorithm: WED Morning 2
Algorithm: MON Afternoon 1
Data Base: TUE Afternoon 2
Wavelet: FRI Morning 4

2
Math: MON Morning 1
Computer: FRI Afternoon 3)";
#endif
    std::unordered_map<std::string, size_t> day2Idx({
        {"MON", 0},
        {"TUE", 1},
        {"WED", 2},
        {"THU", 3},
        {"FRI", 4}
        });
    size_t n;
    while (std::cin >> n) {
        std::vector<std::vector<std::string>> morningCourses(4, std::vector<std::string>(5)), afternoonCourses(3, std::vector<std::string>(5));
        for (size_t i = 0; i < n; ++i) {
            std::string line;
            while (line.empty()) {
                std::getline(std::cin, line);
            }
            std::string course = line.substr(0, line.find(':'));
            std::string remained = line.substr(line.find(':') + 2);
            std::stringstream ss;
            ss << remained << std::endl;
            std::string day;
            std::string timeSection;
            size_t classNum;
            ss >> day >> timeSection >> classNum;
            size_t dayIdx = day2Idx.at(day);
            if (timeSection == "Morning") {
                morningCourses[classNum - 1][dayIdx] = course;
            } else {
                afternoonCourses[classNum - 1][dayIdx] = course;
            }
        }
        printTable(morningCourses, afternoonCourses);
    }
    return 0;
}
