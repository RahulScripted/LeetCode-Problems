// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different. The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void makeCombination(vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target || idx >= candidates.size()) return;

        comb.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back();
        makeCombination(candidates, target, idx + 1, comb, total, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombination(candidates, target, 0, comb, 0, res);
        return res;
    }
};

int main() {
    Solution solution;

    // Test case 1: candidates = {2, 3, 6, 7}, target = 7
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);

    cout << "Combinations for target = " << target1 << " and candidates = {2, 3, 6, 7}:" << endl;
    for (const auto& comb : result1) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }

    // Test case 2: candidates = {2, 3, 5}, target = 8
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = solution.combinationSum(candidates2, target2);

    cout << "\nCombinations for target = " << target2 << " and candidates = {2, 3, 5}:" << endl;
    for (const auto& comb : result2) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }

    return 0;
}