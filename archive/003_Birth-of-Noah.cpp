#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> fatherMap;
unordered_map<string, int> lifeMap;

string processFirstLine(const string &a, const string &b) {
    if (a == "Adam") {
        return "Yes";
    }
    if (b == "Adam") {
        return "No";
    }
    auto it = fatherMap.find(b);
    if (it == fatherMap.end()) {
        return "No enough information";
    }
    while (true) {
        string father = it->second;
        if (father == a) {
            return "Yes";
        } else if (father != "Adam") {
            it = fatherMap.find(it->second);
        } else {
            return "No";
        }
    }
}

string processSecondLIne(const string &a, const string &b) {
    auto itA = lifeMap.find(a);
    auto itB = lifeMap.find(b);
    if (itA == lifeMap.end() || itB == lifeMap.end()) {
        return "No enough information";
    }
    return itA->second > itB->second ? "Yes" : "No";
}

int main(int argc, char *argv[]) {
    fatherMap.emplace("Shem", "Noah");
    fatherMap.emplace("Ham", "Noah");
    fatherMap.emplace("Japheth", "Noah");
    fatherMap.emplace("Noah", "Lamech");
    fatherMap.emplace("Lamech", "Methuselah");
    fatherMap.emplace("Methuselah", "Enoch");
    fatherMap.emplace("Enoch", "Jared");
    fatherMap.emplace("Jared", "Mahalalel");
    fatherMap.emplace("Mahalalel", "Kenan");
    fatherMap.emplace("Kenan", "Enosh");
    fatherMap.emplace("Enosh", "Seth");
    fatherMap.emplace("Seth", "Adam");

    lifeMap.emplace("Adam", 930);
    lifeMap.emplace("Seth", 912);
    lifeMap.emplace("Enosh", 905);
    lifeMap.emplace("Kenan", 910);
    lifeMap.emplace("Mahalalel", 895);
    lifeMap.emplace("Jared", 962);
    lifeMap.emplace("Enoch", 365);
    lifeMap.emplace("Methuselah", 969);
    lifeMap.emplace("Lamech", 777);

#ifdef DEBUG
    vector<pair<string, string>> lines({{"Adam", "Seth"}, {"Shem", "Noah"}});
    for (auto &&p : lines) {
        cout << processFirstLine(p.first, p.second) << endl;
        cout << processSecondLIne(p.first, p.second) << endl;
    }
#else
    string a, b;
    while (cin >> a >> b) {
        cout << processFirstLine(a, b) <<endl;
        cout << processSecondLIne(a, b) <<endl;
    }
#endif

    return 0;
}
