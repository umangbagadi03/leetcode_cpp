#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // dp[i] stores the length of the LIS ending at index i
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    // If nums[i] is greater than nums[j], update the LIS ending at index i
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        // The maximum value in dp array represents the length of the overall LIS
        return *std::max_element(dp.begin(), dp.end());
    }
};
