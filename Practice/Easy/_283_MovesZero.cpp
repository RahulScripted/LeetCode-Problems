// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two Pointer solution (T.C = O(n))
        int left = 0;
        for(int right = 0;right < nums.size();right++){
            if(nums[right] != 0){
                swap(nums[right],nums[left]);
                left++;
            }
        }
        
        // Brute-force Method[T.C = O(n^2)] 
        // int n = nums.size();
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] == 0 && nums[j] != 0) swap(nums[i],nums[j]);
        //     }
        // }
    }
};

void display(vector<int>& nums){
    int n = nums.size();
    for(int i = 0;i < n;i++) cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {0,1,0,3,12};
    cout<<"Before moving zeros : ";
    display(nums); 
    solve.moveZeroes(nums);
    cout<<"After moving zeros : ";
    display(nums); 

    cout<<endl;

    // 2nd Example
    nums = {1,4,5,0,2,0,7,3,0};
    cout<<"Before moving zeros : ";
    display(nums); 
    solve.moveZeroes(nums);
    cout<<"After moving zeros : ";
    display(nums); 
}