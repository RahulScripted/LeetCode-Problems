// Given an integer array nums, return the length of the longest strictly increasing subsequence.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return left;
    }    

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for (int n : nums) {
            if (res.empty() || res.back() < n) res.push_back(n);
            else {
                int idx = binarySearch(res, n);
                res[idx] = n;
            }
        }

        return res.size();       
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int lisLength = sol.lengthOfLIS(nums);
    cout << "The length of the longest increasing subsequence is: " << lisLength << endl;

    return 0;
}