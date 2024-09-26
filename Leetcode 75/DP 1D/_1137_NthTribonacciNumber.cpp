// The Tribonacci sequence Tn is defined as follows: T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0. Given n, return the value of Tn.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        // Optimization
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int temp1 = 0,temp2 = 1,temp3 = 1; 
        for(int i = 3;i <= n;i++){
            int temp = temp1 + temp2 + temp3;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp;
        }
        return temp3;

        // Memorization
        // if(n == 0) return 0;
        // if(n == 1) return 1;
        // if(n == 2) return 1;
        // vector<int>dp(n + 1);
        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 1;
        // for(int i = 3;i <= n;i++){
        //     dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        // }
        // return dp[n];

        // Brute-force Solution
        // if(n == 0) return 0;
        // if(n == 1 || n == 2) return 1;
        // return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};

int main(){
    Solution solve;

    // 1st example
    int n = 4;
    cout<<"For n = "<<n<<" value will be : "<<solve.tribonacci(n)<<endl;

    // 2nd example
    n = 12;
    cout<<"For n = "<<n<<" value will be : "<<solve.tribonacci(n)<<endl;
}