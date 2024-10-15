// Given a string s, return the longest palindromic substring in s.





#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) return false;
            ++left;
            --right;
        }

        return true;
    }

    string longestPalindrome(string s) {
        // Manacher's algo
        if (s.length() <= 1) return s;

        int maxLen = 1;
        string maxStr = s.substr(0, 1);
        s = "#" + regex_replace(s, regex(""), "#") + "#";
        std::vector<int> dp(s.length(), 0);
        int center = 0;
        int right = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (i < right) dp[i] = std::min(right - i, dp[2 * center - i]);
            
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) dp[i]++;
            
            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
            
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                maxStr.erase(remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }
        
        return maxStr;

        // DP Solution
        // if (s.length() <= 1) return s;
        
        // int max_len = 1;
        // int start = 0;
        // int end = 0;
        // vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        // for (int i = 0; i < s.length(); ++i) {
        //     dp[i][i] = true;
        //     for (int j = 0; j < i; ++j) {
        //         if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
        //             dp[j][i] = true;
        //             if (i - j + 1 > max_len) {
        //                 max_len = i - j + 1;
        //                 start = j;
        //                 end = i;
        //             }
        //         }
        //     }
        // }
        
        // return s.substr(start, end - start + 1);

        // Brute-force algo
        // if (s.length() <= 1) return s;

        // int max_len = 1;
        // string max_str = s.substr(0, 1);

        // for (int i = 0; i < s.length(); ++i) {
        //     for (int j = i + max_len; j <= s.length(); ++j) {
        //         if (j - i > max_len && isPalindrome(s.substr(i, j - i))) {
        //             max_len = j - i;
        //             max_str = s.substr(i, j - i);
        //         }
        //     }
        // }

        // return max_str;
    }
};

int main() {
    Solution sol;

    // Example input
    string s = "babad";

    // Call the function and store the result
    string result = sol.longestPalindrome(s);

    // Output the result
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}