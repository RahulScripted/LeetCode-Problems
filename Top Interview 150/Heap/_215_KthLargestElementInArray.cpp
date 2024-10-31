// Given an integer array nums and an integer k, return the kth largest element in the array.




#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Priority Queue (min-heap) to maintain the k largest elements
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (const int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = solution.findKthLargest(nums, k);

    cout << k << "-th largest element is: " << result << endl;

    return 0;
}
