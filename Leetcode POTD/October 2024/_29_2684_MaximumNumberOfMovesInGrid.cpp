// You are given a 0-indexed m x n matrix grid consisting of positive integers. You can start at any cell in the first column of the matrix, and traverse the grid in the following way: From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell. Return the maximum number of moves that you can perform.






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<int> dp(m);

        for (int j = 1; j < n; ++j) {
            int leftTop = 0;
            bool found = false;
            for (int i = 0; i < m; ++i) {
                int cur = -1;
                int nxtLeftTop = dp[i];

                // Check move from top-left cell 
                if (i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i - 1][j - 1]) {
                    cur = max(cur, leftTop + 1);
                }

                // Check move from direct left cell 
                if (dp[i] != -1 && grid[i][j] > grid[i][j - 1]) {
                    cur = max(cur, dp[i] + 1);
                }

                // Check move from bottom-left cell 
                if (i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1]) {
                    cur = max(cur, dp[i + 1] + 1);
                }

                dp[i] = cur;
                found = found || (dp[i] != -1);
                leftTop = nxtLeftTop;
            }

            if (!found) break;
            res = j;
        }

        return res;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {3, 4, 5, 6},
        {3, 2, 6, 8},
        {1, 2, 3, 4}
    };

    int result = solution.maxMoves(grid);
    cout << "Maximum number of moves possible: " << result << endl;

    return 0;
}