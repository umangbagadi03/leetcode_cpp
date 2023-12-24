#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> prefix(n, 1); // Initialize prefix array with 1
        std::vector<long long> product(n, 1); // Initialize product array with 1

        // Calculate prefix products
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Calculate suffix products and update product array
        long long suffixProduct = 1;
        for(int i = n - 1; i >= 0; i--) {
            product[i] = suffixProduct * prefix[i];
            suffixProduct *= nums[i];
        }

        // Convert the product array to int and return
        return std::vector<int>(product.begin(), product.end());
    }
};
