#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
private:
    // Function to find the maximum element in the vector
    int findMax(std::vector<int> &piles) {
        int maxi = INT_MIN;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            maxi = std::max(maxi, piles[i]);
        }
        return maxi;
    }

    // Function to calculate the total hours needed to eat all bananas at a given rate
    long long calculateTotalHours(std::vector<int> &piles, int hourly) {
        long long totalH = 0;  // Change to long long
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalH += std::ceil((double)(piles[i]) / (double)(hourly));
        }
        return totalH;
    }

public:
    // Function to find the minimum rate to eat bananas within the given time
    int minEatingSpeed(std::vector<int> piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
