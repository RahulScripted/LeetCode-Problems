// // You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0. In one operation:

// 1.  choose an index i such that 0 <= i < nums.length,

// 2.  increase your score by nums[i], and

// 3.  replace nums[i] with ceil(nums[i] / 3).

// Return the maximum possible score you can attain after applying exactly k operations. The ceiling function ceil(val) is the least integer greater than or equal to val.






#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < k; i++) {
            int x = pq.top();
            score += x;
            if (x == 1) { // early stop
                score += (k - 1 - i);
                break;
            }
            pq.pop();
            pq.push((x + 2) / 3);
        }
        return score;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 8, 6}; // example input
    int k = 3;
    
    long long result = sol.maxKelements(nums, k);
    cout << "Maximum score after " << k << " operations: " << result << endl;
    
    return 0;
}