// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // Prefix & Suffix
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        // Prefix
        left[0] = height[0];
        for (int i = 1; i < n; i++) left[i] = max(height[i], left[i - 1]);

        // Suffix
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) right[i] = max(height[i], right[i + 1]);

        int ans = 0;
        for (int i = 0; i < n; i++) ans += min(left[i], right[i]) - height[i];

        return ans;

        // Two Pointer
        // int left = 0;
        // int right = height.size() - 1;
        // int leftMax = height[left];
        // int rightMax = height[right];
        // int water = 0;

        // while (left < right) {
        //     if (leftMax < rightMax) {
        //         left++;
        //         leftMax = max(leftMax, height[left]);
        //         water += leftMax - height[left];
        //     } else {
        //         right--;
        //         rightMax = max(rightMax, height[right]);
        //         water += rightMax - height[right];
        //     }
        // }

        // return water; 
    }
};

int main() {
    Solution solution;
    vector<int> height;
    int n, input;

    cout << "Enter the number of elements in the height array: ";
    cin >> n;

    cout << "Enter the elements of the height array: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        height.push_back(input);
    }

    int result = solution.trap(height);
    cout << "The amount of water trapped is: " << result << endl;

    return 0;
}