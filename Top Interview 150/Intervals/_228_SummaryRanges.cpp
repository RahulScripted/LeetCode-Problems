// You are given a sorted unique integer array nums. A range [a,b] is the set of all integers from a to b (inclusive). Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums. Each range [a,b] in the list should be output as:

// 1.  "a->b" if a != b

// 2.  "a" if a == b





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;

        if (n == 0) return res;
        int start = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n || nums[i] != nums[i - 1] + 1) {
                if (start == i - 1) res.push_back(to_string(nums[start]));
                
                else res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));

                start = i; 
            }
        }

        return res;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution solution;
    vector<string> result = solution.summaryRanges(nums);

    cout << "Summary ranges are:" << endl;
    for (const string& range : result) cout << range << endl;
}