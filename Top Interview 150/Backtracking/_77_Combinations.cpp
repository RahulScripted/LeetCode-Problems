// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n]. You may return the answer in any order.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void find(int n, int k, int i, vector<int> &temp, vector<vector<int>> &ans) {
        if (temp.size() == k) { 
            ans.push_back(temp);
            return;
        }
        for (int j = i; j <= n; j++) {
            temp.push_back(j); 
            find(n, k, j + 1, temp, ans);
            temp.pop_back(); 
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(n, k, 1, temp, ans);
        return ans;
    }
};

int main() {
    int n = 4, k = 2;

    Solution solution;
    vector<vector<int>> result = solution.combine(n, k);

    cout << "Combinations of " << k << " numbers from 1 to " << n << ":" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}