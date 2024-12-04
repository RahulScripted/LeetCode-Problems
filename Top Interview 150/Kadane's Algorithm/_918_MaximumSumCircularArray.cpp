// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums. A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n]. A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.





#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int pos = kadane(nums, 1), neg = sum + kadane(nums, -1);
        if (neg > pos && neg == 0) {
            for (int num : nums) {
                if (num == 0) return 0;
            }
            return pos;
        }
        return max(pos, neg);
    }
    
    int kadane(vector<int>& nums, int sign) {
        int global, local;
        global = sign * nums[0];
        local = 0;
        for (int num : nums) {
            local += sign * num;
            global = max(global, local);
            local = max(local, 0);
        }
        return global;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> testCases = {
        {1, -2, 3, -2},
        {5, -3, 5},
        {-3, -2, -3}, 
        {3, -1, 2, -1}, 
        {8, -1, 4, -2, 3}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\nMaximum Circular Subarray Sum: " << solution.maxSubarraySumCircular(testCases[i]) << "\n\n";
    }
}