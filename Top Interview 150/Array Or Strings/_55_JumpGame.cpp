// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position. Return true if you can reach the last index, or false otherwise.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) goal = i;
        }

        return goal == 0;     
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {2,3,1,1,4};
    if(solve.canJump(nums)) cout<<"Jump is possible"<<endl;
    else cout<<"Jump is not possible"<<endl;

    // 2nd Example
    nums = {3,2,1,0,4};
    if(solve.canJump(nums)) cout<<"Jump is possible"<<endl;
    else cout<<"Jump is not possible"<<endl;
}