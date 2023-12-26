#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Get the lengths of the input strings
        int n = text1.size();
        int m = text2.size();

        // Initialize a 2D vector 'dp' to store the lengths of common subsequences
        // dp[i][j] will represent the length of the common subsequence of text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Check if the characters at the current positions match
                if (text1[i - 1] == text2[j - 1]) {
                    // If they match, extend the common subsequence length by 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If they don't match, take the maximum of the lengths from the two adjacent positions
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The result is stored in the bottom-right cell of the DP table
        // It represents the length of the longest common subsequence of the entire strings
        return dp[n][m];
    }
};
