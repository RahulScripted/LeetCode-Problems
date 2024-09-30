// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the sorted rotated array nums of unique elements, return the minimum element of this array.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // Binary Search
        int n = nums.size();
        int lo = 0,hi = (n - 1);
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] < nums[hi]) hi = mid;
            else lo = (mid + 1);
        }
        return nums[lo];
        
        // Linear Search
        // int n = nums.size();
        // int mini =INT_MAX;
        // for(int i = 0;i < n;i++) mini = min(nums[i],mini);

        // return mini;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {3,4,5,1,2};
    cout<<"Minimum value : "<<solve.findMin(nums)<<endl;

    // 2nd example
    nums = {4,5,6,7,0,1,2};
    cout<<"Minimum value : "<<solve.findMin(nums)<<endl;
}