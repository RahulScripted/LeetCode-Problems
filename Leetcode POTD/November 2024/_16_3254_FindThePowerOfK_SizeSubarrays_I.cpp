// You are given an array of integers nums of length n and a positive integer k. The power of an array is defined as:

// 1.  Its maximum element if all of its elements are consecutive and sorted in ascending order.

// 2.  -1 otherwise.

// You need to find the power of all subarrays of nums of size k. Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0;
        int consec_cnt = 1;
        
        for (int r = 0; r < nums.size(); r++) {
            if (r > 0 && nums[r - 1] + 1 == nums[r]) consec_cnt++;
            
            if (r - l + 1 > k) {
                if (nums[l] + 1 == nums[l + 1]) consec_cnt--;
                l++;
            }
            
            if (r - l + 1 == k) res.push_back(consec_cnt == k ? nums[r] : -1);
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1, 2, 3, 5, 6, 7, 8};
    int k = 3;
    vector<int> result = solution.resultsArray(nums, k);

    // Print the result
    cout << "Results Array: ";
    for (int num : result) cout << num << " ";
    cout << endl;
}