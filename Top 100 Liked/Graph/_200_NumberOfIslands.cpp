// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.





#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    bfs(grid, r, c, rows, cols);
                }
            }
        }

        return islands; 
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}