// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// 1.  answer[0] is a list of all distinct integers in nums1 which are not present in nums2.

// 2.  answer[1] is a list of all distinct integers in nums2 which are not present in nums1.





#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> arr1(2);
        unordered_set<int> a(nums1.begin(), nums1.end());
        unordered_set<int> b(nums2.begin(), nums2.end());
        
        for (int i : a) {
            if (b.find(i) == b.end()) arr1[0].push_back(i);
        }

        for (int j : b) {
            if (a.find(j) == a.end()) arr1[1].push_back(j);
        }

        return arr1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = sol.findDifference(nums1, nums2);

    cout << "Difference in nums1 but not in nums2: ";
    for (int num : result[0]) cout << num << " ";
    cout << endl;

    cout << "Difference in nums2 but not in nums1: ";
    for (int num : result[1]) cout << num << " ";
    cout << endl;

    return 0;
}