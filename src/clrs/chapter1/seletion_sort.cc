#include <iostream>
#include <vector>
#include <algorithm>

void SelectionSort(std::vector<int>& nums) {
    int limit = nums.size();
    for (int i = 0; i < limit; ++i) {
        int m = i; // only record min index
        for (int j = i + 1; j < limit; ++j) {
            if (nums[j] < nums[m]) {
                m = j;
            }
        }
        std::swap(nums[i], nums[m]);
    }
}

void SelectionSortDesc(std::vector<int>& nums) {
    int limit = nums.size();
    for (int i = 0; i < limit; ++i) {
        int h = i;
        for (int j = i + 1; j < limit; ++j) {
            if (nums[j] > nums[h]) {
                h = j;
            }
        }
        std::swap(nums[i], nums[h]);
    }
}

int main() {
    std::vector<int> nums{5, 2, 4, 6, 1, 3};
    std::for_each(nums.begin(), nums.end(), [](const int& x) { std::cout << x << ", "; }); std::cout << std::endl;
    SelectionSort(nums);
    std::for_each(nums.begin(), nums.end(), [](const int& x) { std::cout << x << ", "; }); std::cout << std::endl;
    SelectionSortDesc(nums);
    std::for_each(nums.begin(), nums.end(), [](const int& x) { std::cout << x << ", "; }); std::cout << std::endl;
    return 0;
}
