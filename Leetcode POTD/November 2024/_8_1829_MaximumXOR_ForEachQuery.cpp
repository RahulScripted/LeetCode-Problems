// You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times: Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query. Remove the last element from the current array nums. Return an array answer, where answer[i] is the answer to the ith query.






#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xorr = nums[0], maxxorr = pow(2, maximumBit) - 1;
        for (int i = 1; i < n; i++) xorr ^= nums[i];
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = xorr ^ maxxorr;
            xorr ^= nums[n - 1 - i];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3};
    int maximumBit = 2;

    vector<int> result = solution.getMaximumXor(nums, maximumBit);

    cout << "Result: ";
    for (int x : result) cout << x << " ";
    cout << endl;
}