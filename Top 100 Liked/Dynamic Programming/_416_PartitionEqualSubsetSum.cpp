// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.





#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int array_sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (array_sum % 2 != 0) return false;
        int subset_sum = array_sum / 2;
        vector<bool> dp(subset_sum + 1, false);
        dp[0] = true;
        
        // Iterate over all numbers
        for (int num : nums) {
            for (int i = subset_sum; i >= num; --i) dp[i] = dp[i] || dp[i - num];
        }
        
        return dp[subset_sum];
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    if (sol.canPartition(nums)) cout << "The array can be partitioned into two subsets with equal sum.\n";
    else cout << "The array cannot be partitioned into two subsets with equal sum.\n";
}