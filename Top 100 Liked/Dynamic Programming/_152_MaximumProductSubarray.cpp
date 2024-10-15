// Given an integer array nums, find a subarray that has the largest product, and return the product.





#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod = 1;

        // Traverse from the left
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0) prod = 1;
        }

        // Traverse from the right
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0) prod = 1;
        }

        return maxi;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 3, -2, 4};

    // Call the function and store the result
    int result = sol.maxProduct(nums);

    // Output the result
    cout << "Maximum product of subarray: " << result << endl;

    return 0;
}