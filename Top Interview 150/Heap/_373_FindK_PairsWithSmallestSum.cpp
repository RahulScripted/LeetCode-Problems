// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k. Define a pair (u, v) which consists of one element from the first array and one element from the second array. Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.





#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        //first find sum for kth smallest
        long long lo = nums1[0]+nums2[0], hi = nums1[n1-1]+nums2[n2-1];
        while(lo < hi){
            long long mid = (lo+hi)>>1;
            long long ct = 0,j = 0;
            for(int i = 0, j = n2 - 1; i < n1; ++i) {
                while(j >= 0 && nums1[i] + nums2[j] > mid) j--;
                ct += j + 1;
            }
            if(ct < k) lo = mid+1;
            else hi = mid;
        }
        for(long long i=0;i<n1;i++){
            for(long long j=0;(j<n2) && (nums1[i]+nums2[j] < lo);j++){
                ans.push_back({nums1[i],nums2[j]});
            }
        }
        unordered_map<int,int> mp;
        for(auto it:nums2) mp[it]++;
        for(int i=0;i<n1;i++){
            int sz=mp[lo-nums1[i]];
            while(sz>0 && ans.size()<k){
                sz--;
                ans.push_back({nums1[i],(int)(lo-nums1[i])});
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> result = solution.kSmallestPairs(nums1, nums2, k);
    cout << "Example 1: ";
    for (const auto& pair : result) cout << "[" << pair[0] << "," << pair[1] << "] ";
    cout << endl;

    // Example 2
    nums1 = {1, 2};
    nums2 = {3};
    k = 3;
    result = solution.kSmallestPairs(nums1, nums2, k);
    cout << "Example 2: ";
    for (const auto& pair : result) cout << "[" << pair[0] << "," << pair[1] << "] ";
    cout << endl;

    // Example 3
    nums1 = {1, 1, 2};
    nums2 = {1, 2, 3};
    k = 2;
    result = solution.kSmallestPairs(nums1, nums2, k);
    cout << "Example 3: ";
    for (const auto& pair : result) cout << "[" << pair[0] << "," << pair[1] << "] ";
    cout << endl;
}