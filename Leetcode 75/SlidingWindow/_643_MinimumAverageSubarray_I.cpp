// You are given an integer array nums consisting of n elements, and an integer k. Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.






#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Optimized - 2
        int st = 0, end = k - 1;
        double sum = 0, maxSum = 0;
        int n = nums.size();

        // Calculate the initial sum for the first window of size k
        for (int i = st; i <= end; i++) sum += nums[i];
        maxSum = sum;

        // Slide the window
        while (end < n - 1) {
            sum += nums[++end];  // Add next element in the window
            sum -= nums[st++];   // Remove the element that is sliding out
            maxSum = max(sum, maxSum);
        }

        // Calculate and return the maximum average
        double avg = maxSum / k;
        return avg;

        // Optimized
        // double max_avg = numeric_limits<double>::lowest();
        // double w_sum = 0;
        // int n = nums.size();
        // int start = 0;

        // for (int i = 0; i < n; i++) {
        //     w_sum += nums[i];

        //     if ((i - start + 1) == k) {
        //         double avg = w_sum / k;
        //         max_avg = max(avg, max_avg);
        //         w_sum -= nums[start];
        //         start += 1;
        //     }
        // }

        // return max_avg;

        // Brute-force
        // double max = numeric_limits<double>::lowest();
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     double sum = 0;
        //     int count = 0;

        //     for (int j = i; j < i + k && j < n; j++) {
        //         sum += nums[j];
        //         count++;
        //     }

        //     if (count == k) {
        //         double avg = sum / k;
        //         max = std::max(avg, max);
        //     }
        // }

        // return max;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, k, input;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    double result = solution.findMaxAverage(nums, k);

    cout << "The maximum average of any subarray of length " << k << " is: " << result << endl;

    return 0;
}