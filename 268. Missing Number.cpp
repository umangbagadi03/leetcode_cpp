#include <vector>
#include <algorithm>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();

        // Sort the array
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        // If all elements are in place, return the missing number at the end
        return n;
    }
};
