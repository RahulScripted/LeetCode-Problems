// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.





#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = 0;
                for (; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) break;
                }
                if (k == n)  ++ans;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the size of the grid (n x n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the elements of the grid:" << endl;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    int result = solution.equalPairs(grid);
    cout << "Number of equal pairs: " << result << endl;

    return 0;
}