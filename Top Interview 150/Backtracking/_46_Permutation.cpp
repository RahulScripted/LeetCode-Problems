// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }    
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = solution.permute(nums);
    cout << "All permutations:" << endl;
    for (const auto& permutation : result) {
        cout << "[";
        for (size_t i = 0; i < permutation.size(); ++i) {
            cout << permutation[i];
            if (i < permutation.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}