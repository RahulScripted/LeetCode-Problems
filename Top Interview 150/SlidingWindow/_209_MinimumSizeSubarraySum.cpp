// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.





#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = numeric_limits<int>::max();
        int left = 0;
        int curSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            curSum += nums[right];

            while (curSum >= target) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                }
                curSum -= nums[left];
                left++;
            }
        }

        return minLen != numeric_limits<int>::max() ? minLen : 0;        
    }
};

int main() {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    Solution solution;
    int result = solution.minSubArrayLen(target, nums);

    cout << "Minimum subarray length with sum >= target: " << result << endl;

    return 0;
}