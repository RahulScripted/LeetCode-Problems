// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.





#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        long long sum[n]; // prefix sum 0-index
        sum[0] = nums[0];

        int dp[n], front = 0, back = -1, len = 1e9;
        for (int r = 0; r < n; r++) {
            if (r > 0) sum[r] = sum[r - 1] + nums[r];
            if (sum[r] >= k) len = min(len, r + 1);
            while (front <= back && sum[r] - sum[dp[front]] >= k) {
                len = min(len, r - dp[front]);
                front++;
            }
            while (front <= back && sum[r] <= sum[dp[back]]) back--;
            dp[++back] = r;
        }
        return len == 1e9 ? -1 : len;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums;
    int n, k;

    // Input size of array and target sum
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the target sum k: ";
    cin >> k;

    // Input array elements
    cout << "Enter the elements of the array:\n";
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int result = solution.shortestSubarray(nums, k);
    if (result == -1) cout << "No subarray found with sum >= " << k << endl;
    else cout << "The length of the shortest subarray with sum >= " << k << " is: " << result << endl;
}