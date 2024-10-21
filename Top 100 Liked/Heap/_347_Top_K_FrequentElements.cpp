// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int, int> counter;
        for (int n : nums) counter[n]++;
        
        vector<vector<int>> freq(nums.size() + 1);
        for (auto& entry : counter) freq[entry.second].push_back(entry.first);
        
        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int num : freq[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        
        return {};
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << "Enter the value of k (number of top frequent elements to find): ";
    cin >> k;
    
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    
    cout << "Top " << k << " most frequent elements are: ";
    for (int num : result) cout << num << " ";
    cout << endl;
}