// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Given an integer n, return the number of distinct solutions to the n-queens puzzle.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        dfs(n, 0, vector<bool>(n), vector<bool>(2 * n - 1), vector<bool>(2 * n - 1), ans);
        return ans;
    }

private:
    void dfs(int n, int i, vector<bool>&& cols, vector<bool>&& diag1,
             vector<bool>&& diag2, int& ans) {
        if (i == n) {
            ++ans;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (cols[j] || diag1[i + j] || diag2[j - i + n - 1])
                continue;
            cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
            dfs(n, i + 1, std::move(cols), std::move(diag1), std::move(diag2), ans);
            cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of n (number of queens): ";
    cin >> n;

    Solution solution;
    int result = solution.totalNQueens(n);

    cout << "The total number of distinct solutions for " << n << " queens is: " << result << endl;

    return 0;
}