// You are given an m x n grid where each cell can have one of three values:

// 1.  0 representing an empty cell,
// 2.  1 representing a fresh orange, or
// 3.  2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited = grid;
        
        queue<pair<int, int>> q;
        int countFreshOrange = 0;
        
        // Fill the queue with all initially rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) q.push({i, j});
                if (visited[i][j] == 1) countFreshOrange++;
            }
        }

        // If there are no fresh oranges, return 0, if no rotten oranges, return -1
        if (countFreshOrange == 0) return 0;
        if (q.empty()) return -1;
        
        int minutes = -1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        countFreshOrange--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        
        return countFreshOrange == 0 ? minutes : -1;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = solution.orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl;
}