// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            auto up = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            ans += (up - low);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int lower = 3;
    int upper = 8;

    Solution solution;
    long long result = solution.countFairPairs(nums, lower, upper);

    cout << "Number of fair pairs: " << result << endl;

    return 0;
}