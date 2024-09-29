// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary Search
        int left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return left;

        // Linear search
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     if(nums[i] >= target) return i;
        // }
        // return n;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {1,3,5,6};
    int target = 5;
    cout<<target<<" should be inserted at index : "<<solve.searchInsert(nums,target)<<endl;

    // 2nd example
    nums = {1,3,5,6};
    target = 7;
    cout<<target<<" should be inserted at index : "<<solve.searchInsert(nums,target)<<endl;
}