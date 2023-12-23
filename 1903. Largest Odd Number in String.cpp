#include <string>

class Solution {
public:
    // Function to find the largest odd number string from the input string 'num'
    string largestOddNumber(string num) {
        // Iterate from the end of the string towards the beginning
        for (int index = num.size() - 1; index >= 0; --index) {
            // Convert the current character to its numerical value
            int digit = num[index] - '0';

            // Check if the digit is odd using bitwise AND operation
            if ((digit & 1) == 1) {
                // If odd, return the substring from the beginning up to the current index (inclusive)
                return num.substr(0, index + 1);
            }
        }
        // If no odd number is found, return an empty string
        return "";
    }
};
