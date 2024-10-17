// Given an array of integers nums, find the next permutation of nums.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r)
            swap(nums[l++], nums[r--]);
    }

    void nextPermutation(vector<int>& nums) {
        const int n = nums.size();
        int i;
        for (i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) break;
        }

        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }

        reverse(nums, i + 1, n - 1);
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Original: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    solution.nextPermutation(nums1);

    cout << "Next Permutation: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 1};
    cout << "Original: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    solution.nextPermutation(nums2);

    cout << "Next Permutation: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 5};
    cout << "Original: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;

    solution.nextPermutation(nums3);

    cout << "Next Permutation: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;

    return 0;
}