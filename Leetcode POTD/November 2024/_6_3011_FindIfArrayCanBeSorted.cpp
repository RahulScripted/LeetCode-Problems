// You are given a 0-indexed array of positive integers nums. In one operation, you can swap any two adjacent elements if they have the same number of set bits. You are allowed to do this operation any number of times (including zero). Return true if you can sort the array, else return false.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int prevSetBits = 0;
        int prevMax = INT_MIN;  
        int currMax = INT_MIN;  
        int currMin = INT_MAX; 

        for (const int num : nums) {
            const int setBits = __builtin_popcount(num);
            if (setBits != prevSetBits) { 
                if (prevMax > currMin) return false;
                prevSetBits = setBits;
                prevMax = currMax;
                currMax = num;
                currMin = num;
            } 
            else { 
                currMax = max(currMax, num);
                currMin = min(currMin, num);
            }
        }

        return prevMax <= currMin;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {3, 5, 2, 9, 1};
    bool result1 = solution.canSortArray(nums1);
    cout << "Can sort nums1: " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    vector<int> nums2 = {8, 3, 6, 12, 10};
    bool result2 = solution.canSortArray(nums2);
    cout << "Can sort nums2: " << (result2 ? "Yes" : "No") << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5};
    bool result3 = solution.canSortArray(nums3);
    cout << "Can sort nums3: " << (result3 ? "Yes" : "No") << endl;

    return 0;
}