// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// 1.  The length of the subarray is k, and

// 2.  All the elements of the subarray are distinct.

// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> count;
        long long curSum = 0;
        
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            count[nums[r]]++;
            
            if (r - l + 1 > k) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                curSum -= nums[l];
                l++;
            }
            
            if (count.size() == k && (r - l + 1) == k) {
                res = max(res, curSum);
            }
        }
        
        return res;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int k1 = 3;
    cout << "Maximum Subarray Sum for k = " << k1 << ": " << solution.maximumSubarraySum(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {4, 4, 4, 4, 4};
    int k2 = 2;
    cout << "Maximum Subarray Sum for k = " << k2 << ": " << solution.maximumSubarraySum(nums2, k2) << endl;

    // Test case 3
    vector<int> nums3 = {10, 2, -1, 4, 8};
    int k3 = 2;
    cout << "Maximum Subarray Sum for k = " << k3 << ": " << solution.maximumSubarraySum(nums3, k3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 1, 1, 1, 1};
    int k4 = 1;
    cout << "Maximum Subarray Sum for k = " << k4 << ": " << solution.maximumSubarraySum(nums4, k4) << endl;

    return 0;
}