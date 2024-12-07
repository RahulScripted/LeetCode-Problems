// You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations. You can perform the following operation at most maxOperations times: Take any bag of balls and divide it into two new bags with a positive number of balls. Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations. Return the minimum possible penalty after performing the operations.





#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            int ops = 0;
            for (int n : nums) if ((ops += (n - 1) / mid) > maxOps) break;
            ops <= maxOps ? high = mid : low = mid + 1;
        }
        return high;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {9, 7, 8, 5};
    int maxOperations = 4;
    int result = solution.minimumSize(nums, maxOperations);
    cout << "Minimum possible size of the largest bag: " << result << endl;
}