// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Using in-build accumulate
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        // Bit manipulation
        // int n = nums.size();
        // int ans = nums[0];
        // for(int i = 1;i < n;i++) ans ^= nums[i];
        // return ans;

        // Using map
        // int n = nums.size();
        // unordered_map<int,int>freq;
        // for(int i = 0;i < n;i++) freq[nums[i]]++;
        // for(auto x : freq){
        //     if(x.second == 1) return x.first;
        // }
        // return -1;

        // Sorting
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 1;i < n;i+=2){
        //     if(nums[i] != nums[i - 1]) return nums[i - 1];
        // }
        // return nums[n - 1];
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {2,2,1};
    cout<<"Single number : "<<solve.singleNumber(nums)<<endl;

    // 2nd Example
    vector<int>nums = {4,1,2,1,2};
    cout<<"Single number : "<<solve.singleNumber(nums)<<endl;
}