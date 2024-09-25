// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Method 1
        int n = nums.size();
        int lo = 0,hi = (n - 1),mid = 0;
        while(mid <= hi){
            if(nums[mid] == 2){
                swap(nums[mid],nums[hi]);
                hi--;
            }
            else if(nums[mid] == 0){
                swap(nums[mid],nums[lo]);
                lo++;
                mid++;
            }
            else mid++;
        }

        // Method 2
        // int n = nums.size();
        // int countZero = 0,countOne = 0,countTwo = 0;
        
        // // Count
        // for(int i = 0;i < n;i++){
        //     if(nums[i] == 0) countZero++;
        //     else if(nums[i] == 1) countOne++;
        //     else countTwo++;
        // }

        // // Replace
        // for(int i = 0;i < n;i++){
        //     if(i < countZero) nums[i] = 0;
        //     else if(i < (countZero + countOne)) nums[i] = 1;
        //     else nums[i] = 2;
        // }
    }
};

void display(vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i < n;i++) cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {2,0,2,1,1,0};
    cout<<"Before sorting array : ";
    display(nums);
    solve.sortColors(nums);
    cout<<"After sorting array : ";
    display(nums);

    cout<<endl;

    
    // 2nd example
    nums = {2,0,1};
    cout<<"Before sorting array : ";
    display(nums);
    solve.sortColors(nums);
    cout<<"After sorting array : ";
    display(nums);
}