// Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore algorithm
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) candidate = num;
            if (num == candidate) count++;
            else count--;
        }
        
        return candidate;

        // Using map
        // int n = nums.size();
        // unordered_map<int,int>st;
        // for(int i = 0;i < n;i++) st[nums[i]]++;

        // n /= 2;
        // for(auto x : st){
        //     if(x.second > n) return x.first;
        // }
        // return -1;

        // Sorting
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n / 2];
    }
};

int main(){
    Solution solve;

    vector<int>nums = {2,1,2,3,2,1,2};
    cout<<"Majority element : "<<solve.majorityElement(nums)<<endl;
}