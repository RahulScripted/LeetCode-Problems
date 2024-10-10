// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;

        int i = 0;
        for (const char c : t) {
            if (s[i] == c && ++i == s.length()) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;

    string s1 = "abc";
    string t1 = "ahbgdc";

    string s2 = "axc";
    string t2 = "ahbgdc";

    cout << "Is \"" << s1 << "\" a subsequence of \"" << t1 << "\"? " << (sol.isSubsequence(s1, t1) ? "Yes" : "No") << endl;

    cout << "Is \"" << s2 << "\" a subsequence of \"" << t2 << "\"? " << (sol.isSubsequence(s2, t2) ? "Yes" : "No") << endl;

    return 0;
}