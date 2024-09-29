// There is an integer array nums sorted in ascending order (with distinct values). Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary Search
        int left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else{
                 if(target >= nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;

        // Linear search
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     if(nums[i] == target) return i;
        // }
        // return -1;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<target<<" found at index : "<<solve.search(nums,target)<<endl;

    // 2nd example
    nums = {4,5,6,7,0,1,2};
    target = 3;
    cout<<target<<" found at index : "<<solve.search(nums,target)<<endl;

    // 3rd example
    nums = {1};
    target = 0;
    cout<<target<<" found at index : "<<solve.search(nums,target)<<endl;
}