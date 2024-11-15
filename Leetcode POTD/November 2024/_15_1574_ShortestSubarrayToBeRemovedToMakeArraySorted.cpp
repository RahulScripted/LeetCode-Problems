// Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing. Return the length of the shortest subarray to remove.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;
        if (left == n - 1) return 0;

        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) right--;

        int result = min(n - left - 1, right);

        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } 
            else j++;
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    int result = solution.findLengthOfShortestSubarray(arr);
    cout << "The length of the shortest subarray to be removed is: " << result << endl;
}