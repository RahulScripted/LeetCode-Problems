// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.





#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1; 
        
        int sum = 0;
        int ans = 0;
        
        // Traverse the array
        for (auto x : nums) {
            sum += x;
            if (m.find(sum - k) != m.end()) ans += m[sum - k];
            m[sum]++;
        }
        
        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << "Enter the target sum (k): ";
    cin >> k;
    
    Solution solution;
    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays with sum equal to " << k << ": " << result << endl;
}