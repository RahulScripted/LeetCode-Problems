// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array. Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0;
        for (int& num : nums) remainder = (remainder + num) % p;

        // If the remainder is 0 then return 0
        if (remainder == 0) return 0;

        unordered_map<int, int> modIndexMap;
        modIndexMap[0] = -1;
        int n = nums.size(); 
        int minLength = n;
        int currentSum = 0; 

        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;
            int target = (currentSum - remainder + p) % p;
            if (modIndexMap.count(target)) minLength = min(minLength, i - modIndexMap[target]);
            modIndexMap[currentSum] = i;
        }

        return minLength == n ? -1 : minLength;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {3,1,4,2};
    int p = 6;
    cout<<"Length of the smallest subarray will be : "<<solve.minSubarray(nums,p)<<endl;

    // 2nd example
    nums = {6,3,5,2};
    p = 9;
    cout<<"Length of the smallest subarray will be : "<<solve.minSubarray(nums,p)<<endl;
}