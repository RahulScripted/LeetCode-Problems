// You are given an integer array nums and an integer k. In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array. Return the maximum number of operations you can perform on the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> count;

        for (const int num : nums) ++count[num];

        for (const auto& [num, freq] : count){
            if (const auto it = count.find(k - num); it != count.end()) ans += min(freq, it->second);
        }

        return ans / 2;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 5;
    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k2 = 6;

    cout << "Max operations for nums1 with k = " << k1 << ": " << sol.maxOperations(nums1, k1) << endl;

    cout << "Max operations for nums2 with k = " << k2 << ": " << sol.maxOperations(nums2, k2) << endl; 

    return 0;
}