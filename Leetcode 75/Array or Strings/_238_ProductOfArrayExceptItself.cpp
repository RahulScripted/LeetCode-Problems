// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Optimized Approach
        int n = nums.size();
        vector<int>ans(n,0);

        // Prefix Sum
        ans[0] = 1;
        for(int i = 1;i < n;i++) ans[i] = nums[i - 1] * ans[i - 1];

        // Suffix Sum
        int suffix = 1;
        for(int i = (n - 2);i >= 0;i--){
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }
        return ans;

        // Brute-force Approach[Time-limit exceed]
        // int n = nums.size();
        // vector<int> ans;
        // for(int i=0; i<n; i++){
        //     int product = 1;
        //     for(int j=0; j<n; j++){
        //         if(i == j) continue;
        //         product *= nums[j];
        //     }
        //     ans.push_back(product);
        // }
        // return ans;
    }
};

void display(vector<int>&ans){
    int n = ans.size();
    for(int i = 0;i < n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st Example
    vector<int>nums = {1,2,3,4};
    cout<<"Before the product of all the elements : ";
    display(nums);

    vector<int>ans = solve.productExceptSelf(nums);
    cout<<"After the product of all the elements : ";
    display(ans);
}