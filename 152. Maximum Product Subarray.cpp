class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long product = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            product = product * nums[i];

            if (product > maxi) {
                maxi = product;
            }

            // If product becomes zero, reset it to 1
            if (product == 0) {
                product = 1;
            }
        }

        // Reset product for the second pass (from right to left)
        product = 1;

        // Second pass from right to left
        for (int i = n - 1; i >= 0; i--) {
            product = product * nums[i];

            if (product > maxi) {
                maxi = product;
            }

            // If product becomes zero, reset it to 1
            if (product == 0) {
                product = 1;
            }
        }

        return maxi;
    }
};
