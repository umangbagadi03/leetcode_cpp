#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> left(n, 0), right(n, 0);

        // Calculate the number of '0's in the left substring for each index
        int zerosCount = 0;
        for (int i = 0; i < n; i++) {
            zerosCount += (s[i] == '0');
            left[i] = zerosCount;
        }

        // Calculate the number of '1's in the right substring for each index
        int onesCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            onesCount += (s[i] == '1');
            right[i] = onesCount;
        }

        // Calculate the maximum score after splitting the string
        int maxScore = 0;
        for (int i = 0; i < n - 1; i++) {
            int score = left[i] + right[i + 1];
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
