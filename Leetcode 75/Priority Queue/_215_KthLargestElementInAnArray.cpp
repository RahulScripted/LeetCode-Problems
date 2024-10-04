// Given an integer array nums and an integer k, return the kth largest element in the array.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Priority Queue
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (const int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();

        // Sorting
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n - k];
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout<<k<<"th largest element : "<<solve.findKthLargest(nums,k)<<endl;

    // 2nd example
    nums = {3,2,1,5,6,4};
    k = 2;
    cout<<k<<"th largest element : "<<solve.findKthLargest(nums,k)<<endl;
}