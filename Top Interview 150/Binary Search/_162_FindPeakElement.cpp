// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0,hi = (n - 1);
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > nums[mid + 1]) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {1,2,3,1};
    cout<<"Peak element's index : "<<solve.findPeakElement(nums)<<endl;

    // 2nd example
    nums = {1,2,1,3,5,6,4};
    cout<<"Peak element's index : "<<solve.findPeakElement(nums)<<endl;
}