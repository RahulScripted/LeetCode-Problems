// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.





#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int n : nums) {
            if(n <= min1) min1 = n;  
            else if(n <= min2) min2 = n;  
            else return true;  // Found a triplet
        }
        return false;  
    }
};

int main() {
    Solution solution;
    
    // Test case 1: True case
    vector<int> nums1 = {1, 2, 3, 4, 5};
    bool result1 = solution.increasingTriplet(nums1);
    cout << "Test case 1 (nums = {1, 2, 3, 4, 5}): " << (result1 ? "True" : "False") << endl;
    
    // Test case 2: False case
    vector<int> nums2 = {5, 4, 3, 2, 1};
    bool result2 = solution.increasingTriplet(nums2);
    cout << "Test case 2 (nums = {5, 4, 3, 2, 1}): " << (result2 ? "True" : "False") << endl;
    
    // Test case 3: Mixed values (True case)
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    bool result3 = solution.increasingTriplet(nums3);
    cout << "Test case 3 (nums = {2, 1, 5, 0, 4, 6}): " << (result3 ? "True" : "False") << endl;

    return 0;
}