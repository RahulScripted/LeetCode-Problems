// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int dp[105][105];

    bool fdp(int i, int j, string &s1, string &s2, string &s3) {
        int k = i + j; 
        if (i == s1.size() && j == s2.size()) return true;
        if (dp[i][j] != -1) return dp[i][j];

        if (i < s1.size() && s1[i] == s3[k] && fdp(i + 1, j, s1, s2, s3)) {
            return dp[i][j] = true;
        }
        
        if (j < s2.size() && s2[j] == s3[k] && fdp(i, j + 1, s1, s2, s3)) {
            return dp[i][j] = true;
        }
        return dp[i][j] = false; 
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof(dp)); 
        return fdp(0, 0, s1, s2, s3);
    }
};

int main() {
    Solution solution;

    string s1 = "aab";
    string s2 = "axy";
    string s3 = "aaxaby";

    bool result = solution.isInterleave(s1, s2, s3);
    cout << "Is s3 an interleaving of s1 and s2? " << (result ? "Yes" : "No") << endl;

    return 0;
}