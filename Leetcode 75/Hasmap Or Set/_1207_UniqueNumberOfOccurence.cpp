// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.




#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ans;
        for (int i = 0; i < arr.size(); i++) ans[arr[i]]++;

        set<int> freq;
        for (auto it : ans) {
            if (freq.find(it.second) != freq.end()) return false;
            freq.insert(it.second);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    bool result = sol.uniqueOccurrences(arr);
    if (result) cout << "The array has unique occurrences of elements." << endl;

    else cout << "The array does not have unique occurrences of elements." << endl;

    return 0;
}