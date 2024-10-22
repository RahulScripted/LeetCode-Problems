// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.





#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;

        for (int idx = 0; idx < nums.size(); idx++) {
            int num = nums[idx];

            while (!deque.empty() && deque.back() < num) deque.pop_back();
            deque.push_back(num);

            if (idx >= k && nums[idx - k] == deque.front()) deque.pop_front();
            if (idx >= k - 1) res.push_back(deque.front());
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums, k);

    cout << "Maximum values in each sliding window are: ";
    for (int val : result) cout << val << " ";
    cout << endl;
}