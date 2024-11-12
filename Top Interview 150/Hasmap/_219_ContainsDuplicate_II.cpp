// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.





#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Map Solution
        // unordered_map<int, int> seen;

        // for (int i = 0; i < nums.size(); i++) {
        //     int val = nums[i];
        //     if (seen.find(val) != seen.end() && i - seen[val] <= k) return true;
        //     seen[val] = i;
        // }

        // return false;    

        // Set Solution
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) seen.erase(nums[i - k - 1]);
            if (seen.find(nums[i]) != seen.end()) return true;
            seen.insert(nums[i]);
        }

        return false;     
    }
};

int main() {
    Solution solution;

    // Define sample input array and k
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;

    // Call the function with sample input
    bool result = solution.containsNearbyDuplicate(nums, k);

    // Print the result
    if (result) cout << "Contains nearby duplicate within distance " << k << "." << endl;
    else cout << "No nearby duplicate within distance " << k << "." << endl;
}