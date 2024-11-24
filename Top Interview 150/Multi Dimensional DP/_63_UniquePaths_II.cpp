// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time. An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle. Return the number of possible unique paths that the robot can take to reach the bottom-right corner. The testcases are generated so that the answer will be less than or equal to 2 * 10^9.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
    if (i == 0 && j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = uniquePathsMemo(i - 1, j, grid, dp) + uniquePathsMemo(i, j - 1, grid, dp);
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));  
    return uniquePathsMemo(m - 1, n - 1, obstacleGrid, dp);
}
};

int main() {
    Solution solution;

    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    cout << "Enter the grid elements (0 for free space, 1 for obstacle):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    int result = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << "The number of unique paths is: " << result << endl;
}