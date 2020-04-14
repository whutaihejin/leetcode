#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // [1, 2, 5]
    // dp[i][j] means if we can combine sum i with 0,1,...,j elements of nums
    // dp[i][j] = dp[i - nums[j]][j - 1] || dp[i][j - 1]
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 1) return false;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum & 0x01) return false;
        sum /= 2;
        vector<vector<bool>> dp(sum + 1, vector<bool>(nums.size() + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= sum; ++i) {
            for (int j = 1; j <= nums.size(); ++j) {
                dp[i][j] = dp[i][j - 1];
                if (i >= nums[j - 1]) {
                    dp[i][j] = dp[i][j] | dp[i - nums[j - 1]][j - 1];
                }
            }
        }
        return dp[sum][nums.size()];
    }
};

int main() {
    Solution s;
    {
        vector<int> nums{1, 2, 5};
        assert(false == s.canPartition(nums));
    }
    {
        vector<int> nums{3,3,3,4,5};
        assert(s.canPartition(nums));
    }
    {
        vector<int> nums{1,5,11,5};
        assert(s.canPartition(nums));
    }
    return 0;
}
