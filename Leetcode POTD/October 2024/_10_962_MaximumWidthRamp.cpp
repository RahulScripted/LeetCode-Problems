// A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i. Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        stack<int> stack;

        for (int i = 0; i < nums.size(); ++i){
            if (stack.empty() || nums[i] < nums[stack.top()]) stack.push(i);
        }

        for (int i = nums.size() - 1; i > ans; --i){
            while (!stack.empty() && nums[i] >= nums[stack.top()]) ans = max(ans, i - stack.top()), stack.pop();
        }

        return ans;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {6,0,8,2,1,5};
    cout<<"Maximum width : "<<solve.maxWidthRamp(nums)<<endl;
}