// here is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time. Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n,int i = 0,int j = 0) {
        // Math
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) ans = (ans * i) / j;
        return ans;

        // Single vector
        // vector<int> dp(n, 1);
        // for(int i = 1; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         dp[j] += dp[j-1];   
        //     }
        // }
        // return dp[n-1];

        // DP
        // vector<vector<int>> dp(m, vector<int>(n, 1));
        // for(int i = 1; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        //     }
        // } 
        // return dp[m-1][n-1];

        // Brute Force
        // if(i == (m - 1) || j == (n - 1)) return 1;
        // return uniquePaths(m,n,i + 1,j) + uniquePaths(m,n,i,j + 1);
    }
};

int main(){
    Solution solve;

    // 1st Example
    int m = 3,n = 7;
    cout<<"No. of unique paths : "<<solve.uniquePaths(m,n)<<endl;

    // 2nd Example
    m = 3,n = 2;
    cout<<"No. of unique paths : "<<solve.uniquePaths(m,n)<<endl;
}