// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.





#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stack;

        for (int i = 0; i <= heights.size(); ++i) {
            while (!stack.empty() && (i == heights.size() || heights[stack.top()] > heights[i])) {
                const int h = heights[stack.top()];
                stack.pop();
                const int w = stack.empty() ? i : i - stack.top() - 1;
                ans = max(ans, h * w);
            }
            stack.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {2, 4};

    cout << "Largest Rectangle Area for heights1: " << sol.largestRectangleArea(heights1) << endl;

    cout << "Largest Rectangle Area for heights2: " << sol.largestRectangleArea(heights2) << endl;

    return 0;
}