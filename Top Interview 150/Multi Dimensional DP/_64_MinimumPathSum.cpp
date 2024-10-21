// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (i > 0 && j > 0) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0) grid[i][0] += grid[i - 1][0];
                else if (j > 0) grid[0][j] += grid[0][j - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
};

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Original Grid:" << endl;
    printGrid(grid);

    Solution sol;
    int minSum = sol.minPathSum(grid);
    cout << "Grid after computing minimum path sums:" << endl;
    printGrid(grid);
    cout << "Minimum Path Sum: " << minSum << endl;
}