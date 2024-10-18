// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0. A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. A common subsequence of two strings is a subsequence that is common to both strings.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int space_optimisation(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 < len2) {
            swap(str1, str2);
            swap(len1, len2);
        }
        vector<int> dp(len2 + 1, 0);
        for (int i = 1; i <= len1; i++) {
            int prev = 0;
            for (int j = 1; j <= len2; j++) {
                int temp = dp[j];
                if (str1[i - 1] == str2[j - 1]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j-1]);
                prev = temp;
            }
        }
        return dp[len2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return space_optimisation(text1, text2);
    }
};

int main() {
    Solution solution;
    
    string text1 = "abcde";
    string text2 = "ace";
    int result = solution.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl;
}