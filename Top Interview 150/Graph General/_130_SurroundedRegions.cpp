// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// 1.  Connect: A cell is connected to adjacent cells horizontally or vertically.

// 2.  Region: To form a region connect every 'O' cell.

// 3.  Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

// A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.





#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int row, int col, int r[], int c[], vector<vector<int>> &visited, vector<vector<char>> &board) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, r, c, visited, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int r[] = {1, 0, -1, 0};
        int c[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(i, 0, r, c, visited, board);
            }
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0) {
                dfs(i, m - 1, r, c, visited, board);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && visited[0][j] == 0) {
                dfs(0, j, r, c, visited, board);
            }
            if (board[n - 1][j] == 'O' && visited[n - 1][j] == 0) {
                dfs(n - 1, j, r, c, visited, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board:" << endl;
    printBoard(board);

    solution.solve(board);
    cout << "\nModified Board:" << endl;
    printBoard(board);
}