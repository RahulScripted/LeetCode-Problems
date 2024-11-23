// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Approach 5 [Using length]
        unordered_set<int>check(nums.begin(),nums.end());
        return check.size() < nums.size();

        // Approach 4 [Using Set]
        // unordered_set<int>check;
        // for(int num : nums){
        //     if(check.count(num)) return true;
        //     check.insert(num);
        // }
        // return false;

        // Approach 3 [Using Map]
        // unordered_map<int,int>mp;
        // int n = nums.size();
        // for(int i = 0;i < n;i++) mp[nums[i]]++;
        // for(auto x:mp){
        //     if(x.second > 1) return true;
        // }
        // return false;

        // Approach 2 [Using Sorting]
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 0;i < (n - 1);i++){
        //     if(nums[i] == nums[i + 1]) return true;
        // }
        // return false;

        // Approach 1 [Brute-force]
        // int n = nums.size();
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;
    }
};

int main(){
    Solution solve;

    vector<int>nums = {1,2,3,1};
    if(solve.containsDuplicate(nums)) cout<<"Duplicate exist"<<endl;
    else cout<<"Duplicate doesn't exist"<<endl;
}