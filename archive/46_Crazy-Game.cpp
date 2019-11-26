#include <bits/stdc++.h>

size_t calcMinimumTimeOfChanges(const std::vector<size_t> &nums) {
    size_t n = nums.size();
    size_t result = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (nums[i] > nums[j]) {
                result++;
            }
        }
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
    std::cin << R"(1
4
4 3 2 1)";
#endif
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;
        std::vector<size_t> nums(n);
        for (size_t j = 0; j < n; ++j) {
            std::cin >> nums[j];
        }
        std::cout << calcMinimumTimeOfChanges(nums) << std::endl;
    }
    return 0;
}
