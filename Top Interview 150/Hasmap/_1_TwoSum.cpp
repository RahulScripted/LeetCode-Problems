// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hashing (one-pass)
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) return {numMap[complement], i};
            numMap[nums[i]] = i;
        }

        return {}; 

        // Hashing(Two-pass)
        // unordered_map<int, int> numMap;
        // int n = nums.size();

        // // Build the hash table
        // for (int i = 0; i < n; i++) numMap[nums[i]] = i;

        // // Find the complement
        // for (int i = 0; i < n; i++) {
        //     int complement = target - nums[i];
        //     if (numMap.count(complement) && numMap[complement] != i) {
        //         return {i, numMap[complement]};
        //     }
        // }

        // return {};

        // Brute-force
        // int n = nums.size();

        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if((nums[i] + nums[j]) == target) return {i,j};
        //     }
        // }
        // return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, target, input;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = solution.twoSum(nums, target);

    if (result.empty()) cout << "No solution found." << endl;

    else cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;

    return 0;
}