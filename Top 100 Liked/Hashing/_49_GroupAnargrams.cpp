// Given an array of strings strs, group the anagrams together. You can return the answer in any order.





#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto x : strs) {
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for (auto x : mp) ans.push_back(x.second);
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs;
    int n;
    string input;

    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        strs.push_back(input);
    }

    vector<vector<string>> result = solution.groupAnagrams(strs);

    cout << "Grouped anagrams are: " << endl;
    for (const auto& group : result) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}