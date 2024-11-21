// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively. A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it. Return the number of unoccupied cells that are not guarded.





#include <iostream>
#include <vector>
#include <cstring> // for memset
#include <algorithm> // for std::count

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g[m][n];
        memset(g, 0, sizeof(g));
        
        // Mark guards and walls as 2
        for (auto& e : guards) g[e[0]][e[1]] = 2;
        for (auto& e : walls) g[e[0]][e[1]] = 2;
        
        // Directions: up, right, down, left
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (auto& e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int dx = dirs[k], dy = dirs[k + 1];
                
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && g[x + dx][y + dy] < 2) {
                    x += dx;
                    y += dy;
                    g[x][y] = 1;
                }
            }
        }
        
        // Count unguarded cells (cells with value 0)
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) unguardedCount += count(g[i], g[i] + n, 0);
        return unguardedCount;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int m1 = 4, n1 = 6;
    vector<vector<int>> guards1 = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls1 = {{0, 1}, {2, 2}, {1, 4}};
    cout << "Unguarded cells (Example 1): " << solution.countUnguarded(m1, n1, guards1, walls1) << endl;
    
    // Example 2
    int m2 = 3, n2 = 3;
    vector<vector<int>> guards2 = {{1, 1}};
    vector<vector<int>> walls2 = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    cout << "Unguarded cells (Example 2): " << solution.countUnguarded(m2, n2, guards2, walls2) << endl;
    
    // Example 3
    int m3 = 5, n3 = 5;
    vector<vector<int>> guards3 = {{2, 2}};
    vector<vector<int>> walls3 = {{1, 2}, {2, 1}, {3, 2}, {2, 3}};
    cout << "Unguarded cells (Example 3): " << solution.countUnguarded(m3, n3, guards3, walls3) << endl;
}