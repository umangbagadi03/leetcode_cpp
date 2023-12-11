class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1;  // Initialize count to 1, as the first element is always counted.
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;

                if (count > n / 4) {
                    return arr[i];
                }
            } else {
                count = 1;  // Reset count for a new element.
            }
        }

        // If the loop completes without finding a special integer, return the last element.
        return arr.back();
    }
};
