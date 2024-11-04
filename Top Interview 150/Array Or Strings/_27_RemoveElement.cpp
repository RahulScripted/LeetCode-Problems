// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val. Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things: Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums. Return k.






#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    Solution solution;

    // Test case input
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    // Call the function
    int newSize = solution.removeElement(nums, val);

    // Output the result
    cout << "[";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i];
        if (i < newSize - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}