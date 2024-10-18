// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If target is not found in the array, return [-1, -1].





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                startingPosition = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == target) {
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "Starting and ending position of target " << target << " : [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}