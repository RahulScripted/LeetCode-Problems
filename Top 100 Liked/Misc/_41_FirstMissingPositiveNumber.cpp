// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Cyclic Sort
        int n = nums.size();

        // Step 1: Place each number in its correct position (1 should go to index 0, 2 to index 1, and so on)
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first index where the value is not (index + 1)
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        
        return n + 1;

        // Using Set
        // unordered_set<int> set;
        // for (int num : nums)    set.insert(num);

        // int i = 1;
        // while (i <= nums.size()) {
        //     if (set.find(i) != set.end())   i++;
        //     else return i;
        // }
        // return nums.size() + 1;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {1,2,0};
    cout<<"First missing positive number : "<<solve.firstMissingPositive(nums)<<endl;

    // 2nd Example
    nums = {3,4,-1,1};
    cout<<"First missing positive number : "<<solve.firstMissingPositive(nums)<<endl;
}