// You are given an array nums of non-negative integers and an integer k. An array is called special if the bitwise OR of all of its elements is at least k. Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.





#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        int start = 0, end = 0, minLength = INT_MAX;

        while (end < nums.size()) {
            updateBits(count, nums[end], 1);
            while (start <= end && getVal(count) >= k) {
                minLength = min(minLength, end - start + 1);
                updateBits(count, nums[start], -1);
                start++;
            }
            end++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    void updateBits(vector<int>& count, int num, int val) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                count[i] += val;
            }
        }
    }

    int getVal(const vector<int>& count) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 4, 8}; // Example input
    int k = 7; // Example target

    int result = solution.minimumSubarrayLength(nums, k);
    if (result != -1) cout << "The minimum subarray length with bitwise OR >= " << k << " is " << result << endl;

    else cout << "No subarray with bitwise OR >= " << k << " exists." << endl;
}