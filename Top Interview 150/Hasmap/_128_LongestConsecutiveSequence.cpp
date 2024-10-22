// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.





#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) length++;
                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length in test case 1: " << solution.longestConsecutive(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 1};
    cout << "Longest consecutive sequence length in test case 2: " << solution.longestConsecutive(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {};
    cout << "Longest consecutive sequence length in test case 3: " << solution.longestConsecutive(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {9, 1, 5, 3, 4, 2, 7, 6};
    cout << "Longest consecutive sequence length in test case 4: " << solution.longestConsecutive(nums4) << endl;

    // Test case 5
    vector<int> nums5 = {10, 20, 30};
    cout << "Longest consecutive sequence length in test case 5: " << solution.longestConsecutive(nums5) << endl;

    return 0;
}