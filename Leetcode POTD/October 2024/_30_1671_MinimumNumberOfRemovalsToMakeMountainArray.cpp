// Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftDP(n, 1), rightDP(n, 1);
        // Find LIS from left
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) leftDP[i] = max(leftDP[i], leftDP[j] + 1);
            }
        }

        // Find LIS from right
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = nums.size() - 1; j > i; --j) {
                if (nums[i] > nums[j]) rightDP[i] = max(rightDP[i], rightDP[j] + 1);
            }
        }

        // Find largest mountain by finding largest sum
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (leftDP[i] != 1 && rightDP[i] != 1) ans = max(ans, leftDP[i] + rightDP[i]);
        }
        return nums.size() - ans + 1;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout<<"The minimum number of elements to removal required will be : "<<solve.minimumMountainRemovals(nums)<<endl;

    // 2nd Example
    nums = {1,3,1};
    cout<<"The minimum number of elements to removal required will be : "<<solve.minimumMountainRemovals(nums)<<endl;
}