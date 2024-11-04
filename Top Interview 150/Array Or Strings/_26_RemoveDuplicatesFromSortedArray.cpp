// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums. Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things: Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums. Return k.






#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int j = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    Solution solution;

    // Test case input
    vector<int> nums = {1, 1, 2};

    // Call the function
    int newSize = solution.removeDuplicates(nums);

    // Output the result
    cout << "[";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i];
        if (i < newSize - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}