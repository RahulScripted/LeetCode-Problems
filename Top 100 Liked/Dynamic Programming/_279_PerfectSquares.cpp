// Given an integer n, return the least number of perfect square numbers that sum to n.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i){
            for (int j = 1; j * j <= i; ++j) dp[i] = min(dp[i], dp[i - j * j] + 1);
        }

        return dp[n];
    }
};

int main(){
    Solution solve;

    // 1st Example
    int n = 12;
    cout<<"The least number is : "<<solve.numSquares(n)<<endl;

    // 2nd Example
    n = 16;
    cout<<"The least number is : "<<solve.numSquares(n)<<endl;
}