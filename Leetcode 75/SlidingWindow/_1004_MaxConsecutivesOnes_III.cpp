// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) --k;
            while (k < 0){
                if (nums[l++] == 0) ++k;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<"The maximum number of consecutive 1's will be : "<<solve.longestOnes(nums,k)<<endl;
}