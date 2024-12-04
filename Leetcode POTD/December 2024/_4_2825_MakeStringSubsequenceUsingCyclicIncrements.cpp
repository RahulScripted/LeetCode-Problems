// You are given two 0-indexed strings str1 and str2. In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'. Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int targetIdx = 0;
        int targetLen = str2.length();
        for (char currChar : str1) {
            if (targetIdx < targetLen && (str2[targetIdx] - currChar + 26) % 26 <= 1) targetIdx++;
        }
        return targetIdx == targetLen;
    }
};

int main() {
    Solution solution;
    string str1, str2;

    // Example 1
    str1 = "abcde";
    str2 = "ace";
    cout << "Can make subsequence (\"" << str1 << "\", \"" << str2 << "\"): " << (solution.canMakeSubsequence(str1, str2) ? "true" : "false") << endl;

    // Example 2
    str1 = "zab";
    str2 = "bca";
    cout << "Can make subsequence (\"" << str1 << "\", \"" << str2 << "\"): " << (solution.canMakeSubsequence(str1, str2) ? "true" : "false") << endl;

    // Example 3
    str1 = "xyz";
    str2 = "xy";
    cout << "Can make subsequence (\"" << str1 << "\", \"" << str2 << "\"): " << (solution.canMakeSubsequence(str1, str2) ? "true" : "false") << endl;

    return 0;
}