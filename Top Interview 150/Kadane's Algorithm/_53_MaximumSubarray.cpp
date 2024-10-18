// Given an integer array nums, find the subarray with the largest sum, and return its sum.





#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int solve(vector<int>& A, int i, bool mustPick) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;       
        if(mustPick) return max(0, A[i] + solve(A, i+1, true));    
        else return max(solve(A, i+1, false), A[i] + solve(A, i+1, true));    
    }

    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }

    int maxSubArray(vector<int>& nums) {
        // Kedane's algo
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums){
            curMax = max(c, curMax + c);
            maxTillNow = max(maxTillNow, curMax);
        }
        return maxTillNow;

        // Tabulation with single vector
        // vector<int> dp(nums);
        // for(int i = 1; i < size(nums); i++) 
        //     dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        // return *max_element(begin(dp), end(dp));

        // Tabulation with 2D vector
        // vector<vector<int>> dp(2, vector<int>(size(nums)));
        // dp[0][0] = dp[1][0] = nums[0];
        // for(int i = 1; i < size(nums); i++) {
        //     dp[1][i] = max(nums[i], nums[i] + dp[1][i-1]);
        //     dp[0][i] = max(dp[0][i-1], dp[1][i]);
        // }
        // return dp[0].back();

        // DP
        // vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        // return solve(nums, 0, false, dp);

        // Recursive
        // return solve(nums, 0, false);

        // Brute-force
        // int n = size(nums), ans = INT_MIN;
        // for(int i = 0; i < n; i++) 
        //     for(int j = i, curSum = 0; j < n ; j++) 
        //         curSum += nums[j],
        //         ans = max(ans, curSum);        
        // return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int maxSum = sol.maxSubArray(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}