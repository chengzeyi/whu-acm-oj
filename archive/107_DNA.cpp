#include <bits/stdc++.h>

std::unordered_map<char, size_t>
    nucleotide2Idx({{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'-', 4}});

std::vector<std::vector<int>> matrix({{5, -1, -2, -1, -3},
                                      {-1, 5, -3, -2, -4},
                                      {-2, -3, 5, -2, -2},
                                      {-1, -2, -2, 5, -1},
                                      {-3, -4, -2, -1, 0}});

int getScore(char a, char b) {
    return matrix[nucleotide2Idx.at(a)][nucleotide2Idx.at(b)];
}

int calcSimilarityInner(const std::string &a, const std::string &b, size_t ia,
                        size_t ib, std::vector<std::vector<int>> &cache) {
    int &cached = cache[ia][ib];
    if (cached != std::numeric_limits<int>::max()) {
        return cached;
    }
    int score = 0;
    if (a.size() == ia) {
        while (ib < b.size()) {
            score += getScore(b[ib], '-');
            ++ib;
        }
        goto END;
    }
    if (b.size() == ib) {
        while (ia < a.size()) {
            score += getScore(a[ia], '-');
            ++ia;
        }
        goto END;
    }
    score = std::max(
        {calcSimilarityInner(a, b, ia + 1, ib, cache) + getScore(a[ia], '-'),
         calcSimilarityInner(a, b, ia, ib + 1, cache) + getScore(b[ib], '-'),
         calcSimilarityInner(a, b, ia + 1, ib + 1, cache) +
             getScore(a[ia], b[ib])});
END:
    cached = score;
    return score;
}

int calcSimilarity(const std::string &a, const std::string &b) {
    std::vector<std::vector<int>> cache(
        a.size() + 1,
        std::vector<int>(b.size() + 1, std::numeric_limits<int>::max()));
    return calcSimilarityInner(a, b, 0, 0, cache);
}

#ifdef DEBUG
#define cin _ss
namespace std {
stringstream _ss;
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    std::cin << R"(2
7 AGTGATG
5 GTTAG
7 AGCTATT
9 AGCTTTAAA)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::string a, b;
        std::cin >> a;
        std::cin >> n;
        std::cin >> b;
        std::cout << calcSimilarity(a, b) << std::endl;
    }
    return 0;
}
