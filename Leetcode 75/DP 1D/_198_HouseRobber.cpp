// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // T.C -> O(n) && S.C -> O(n)
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp.back();

        // T.C -> O(n) && S.C -> O(1)
        // int odd = 0,even = 0;
        // int n = nums.size();
        
        // for(int i = 0;i < n;i++){
        //     const int dp = max(odd, even + nums[i]);
        //     even = odd;
        //     odd = dp;
        // }

        // return max(odd,even);
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Maximum money that can be robbed: " << solution.rob(nums1) << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Maximum money that can be robbed: " << solution.rob(nums2) << endl;
    
    // Test case 3
    vector<int> nums3 = {5, 3, 4, 11, 2};
    cout << "Maximum money that can be robbed: " << solution.rob(nums3) << endl;

    return 0;
}