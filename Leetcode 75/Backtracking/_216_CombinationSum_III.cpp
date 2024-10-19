// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// 1.  Only numbers 1 through 9 are used.
// 2.  Each number is used at most once.

// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int index, vector<int>& currList, int total, int k, int n, vector<vector<int>>& res) {
        if (currList.size() == k) {
            if (total == n) res.push_back(currList); 
            return;
        }

        for (int i = index; i <= 9; ++i) {
            int currTotal = total + i;
            if (currTotal <= n) {
                currList.push_back(i);
                dfs(i + 1, currList, currTotal, k, n, res);
                currList.pop_back();
            } 
            else return;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > 45 || k > n) return {};

        vector<vector<int>> res;
        vector<int> currList;

        // Helper function
        dfs(1, currList, 0, k, n, res);
        return res;
    }
};

int main() {
    Solution sol;
    int k, n;

    cout << "Enter the value of k (number of elements): ";
    cin >> k;
    cout << "Enter the value of n (target sum): ";
    cin >> n;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "Combinations of " << k << " numbers that sum up to " << n << ":\n";
    for (const auto& combination : result) {
        for (int num : combination) cout << num << " ";
        cout << endl;
    }
}