// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); i++) {
            for (const string& w : wordDict) {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()]; 
    }
};

int main() {
    Solution solution;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool result = solution.wordBreak(s, wordDict);

    if (result) cout << "The string can be segmented into words from the dictionary." << endl;

    else cout << "The string cannot be segmented into words from the dictionary." << endl;
}