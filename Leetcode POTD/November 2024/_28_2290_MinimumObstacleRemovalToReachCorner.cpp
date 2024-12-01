// You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

// 1.  0 represents an empty cell,

// 2.  1 represents an obstacle that may be removed.


// You can move up, down, left, or right from and to an empty cell. Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).





#include <iostream>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        distance[0][0] = 0;
        dq.push_front({0, 0});
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = distance[x][y] + grid[nx][ny];
                    if (newDist < distance[nx][ny]) {
                        distance[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) dq.push_front({nx, ny});
                        else dq.push_back({nx, ny});
                    }
                }
            }
        }
        return distance[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1},
        {1, 1, 0},
        {1, 0, 0}
    };

    Solution solution;
    int result = solution.minimumObstacles(grid);
    cout << "Minimum obstacles to remove: " << result << endl;

    return 0;
}