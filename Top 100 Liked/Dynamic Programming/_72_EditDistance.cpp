// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:

// 1.  Insert a character

// 2.  Delete a character

// 3.  Replace a character






#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if (i >= s1.size()) return s2.size() - j;  // Insert remaining characters from s2
        if (j >= s2.size()) return s1.size() - i;  // Delete remaining characters from s1
        if (dp[i][j] != -1) return dp[i][j];       // Return cached result

        if (s1[i] == s2[j]) return dp[i][j] = f(i + 1, j + 1, s1, s2, dp);  // If characters match, move both pointers

        int insert = 1 + f(i, j + 1, s1, s2, dp);   // Insert a character
        int delete_op = 1 + f(i + 1, j, s1, s2, dp);  // Delete a character
        int replace = 1 + f(i + 1, j + 1, s1, s2, dp);  // Replace a character

        return dp[i][j] = min({insert, delete_op, replace});  // Take the minimum of the three operations
    }

    int minDistance(string word1, string word2) {
        // Approach 1
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return f(0, 0, word1, word2, dp);

        // Approach 2
        // int n=word1.size();
        // int m=word2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // for(int i=0;i<=n;i++) dp[i][0]=i;
        // for(int j=0;j<=m;j++) dp[0][j]=j;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(word1[i-1]==word2[j-1]) dp[i][j]= 0 + dp[i-1][j-1];
        //         else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        //     }
        // }
        // return dp[n][m];
    }
};

int main() {
    Solution sol;

    // Example input
    string word1 = "horse";
    string word2 = "ros";

    // Call the function and store the result
    int result = sol.minDistance(word1, word2);

    // Output the result
    cout << "Minimum edit distance: " << result << endl;

    return 0;
}