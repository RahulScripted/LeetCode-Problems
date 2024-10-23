// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.





#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) k--;
                else if (total < 0) j++;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }
        return res;        
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>>& res) {
    for (const auto& triplet : res) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test case 1 - Triplets adding to zero in [-1, 0, 1, 2, -1, -4]:\n";
    vector<vector<int>> result1 = sol.threeSum(nums1);
    printResult(result1);

    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    cout << "Test case 2 - Triplets adding to zero in [0, 1, 1]:\n";
    vector<vector<int>> result2 = sol.threeSum(nums2);
    printResult(result2);

    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    cout << "Test case 3 - Triplets adding to zero in [0, 0, 0]:\n";
    vector<vector<int>> result3 = sol.threeSum(nums3);
    printResult(result3);

    return 0;
}