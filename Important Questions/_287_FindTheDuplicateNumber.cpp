// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number. You must solve the problem without modifying the array nums and using only constant extra space.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Using another vector
        int n = nums.size();
        vector<bool>check(n,false);
        for(int i = 0;i < n;i++){
            if(check[nums[i]] == true) return nums[i];
            check[nums[i]] = true;
        }
        return -1;

        // Sort
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 1;i < n;i++){
        //     if(nums[i] == nums[i - 1]) return nums[i];
        // }
        // return -1;

        // Using Map
        // int n = nums.size();
        // unordered_map<int,int>mp;
        // for(int i = 0;i < n;i++) mp[nums[i]]++;
        // for(auto x : mp){
        //     if(x.second > 1) return x.first;
        // }
        // return -1;

        // Brute-force Approach [Gives TLE]
        // int n = nums.size();
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] == nums[j]) return nums[j];
        //     }
        // }
        // return -1;
    }
};

int main(){
    Solution solve;

    vector<int>nums = {1,2,3,5,1};
    cout<<"Duplicate Number is : "<<solve.findDuplicate(nums)<<endl;
}