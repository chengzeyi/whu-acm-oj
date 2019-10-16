#include <bits/stdc++.h>
#include <complex>

using namespace std;

unordered_map<string, double> metric2Meter;

double disaster;

double normalize(double v, const string &m) {
    auto it = metric2Meter.find(m);
    if (it == metric2Meter.end()) {
        exit(1);
    }
    return v * it->second;
}

string calcStability(
    double l,
    double w,
    double h,
    const string &m1,
    const string &m2,
    const string &m3
) {
    l = normalize(l, m1);
    w = normalize(w, m2);
    h = normalize(h, m3);
    if (std::abs(l - w * 6.0) < 1e-9) {
        return "Excellent";
    }
    if (std::abs(l - w) < 1e-9) {
        return "Spin";
    }
    return "Neither";
}

int main(int argc, char *argv[]) {
    metric2Meter.emplace("meters", 1.0);
    metric2Meter.emplace("centimeters", 0.01);
    metric2Meter.emplace("inches", 0.4572 / 18.0);
    metric2Meter.emplace("cubits", 0.4572);
    metric2Meter.emplace("feet", 137.16 / 450.0);
    disaster = normalize(120.0, "cubits");

#ifdef DEBUG
    vector<vector<pair<double, string>>> inputs({
        {{120, "cubits"}, {120, "cubits"}, {110, "cubits"}},
        {{450, "feet"}, {22.86, "meters"}, {30, "cubits"}}
    });
    for (auto &&v : inputs) {
        cout << calcStability(
            v[0].first,
            v[1].first,
            v[2].first,
            v[0].second,
            v[1].second,
            v[2].second
        ) << endl << endl;
    }
#else
    double v1, v2, v3;
    string m1, m2, m3;
    while (cin >> v1 >>m1 >> v2 >> m2 >> v3 >> m3) {
        cout << calcStability(
                v1, v2, v3,
                m1, m2, m3
        ) << endl << endl;
    }
#endif

    return 0;
}
