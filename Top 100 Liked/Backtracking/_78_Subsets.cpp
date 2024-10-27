// Given an integer array nums of unique elements, return all possible subsets (the power set).





#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;        
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }    
};

int main() {
    Solution solution;
    
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = solution.subsets(nums);
    cout << "All subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}