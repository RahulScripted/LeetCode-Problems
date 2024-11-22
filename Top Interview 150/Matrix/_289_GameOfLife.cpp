// Given the current state of the board, update the board to reflect its next state.




#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int checkEightNeighbours(int n, int m, vector<vector<int>>& board, int i, int j) {
        int countOnes = 0;

        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1) countOnes++;
        
        if (i - 1 >= 0 && board[i - 1][j] == 1) countOnes++;
        
        if (i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == 1) countOnes++;
        
        if (j - 1 >= 0 && board[i][j - 1] == 1) countOnes++;
        
        if (j + 1 < m && board[i][j + 1] == 1) countOnes++;
        
        if (i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == 1) countOnes++;
        
        if (i + 1 < n && board[i + 1][j] == 1) countOnes++;
        
        if (i + 1 < n && j + 1 < m && board[i + 1][j + 1] == 1) countOnes++;

        return countOnes;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> newBoard(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int countOnes = checkEightNeighbours(n, m, board, i, j);
                if (board[i][j] == 0) {
                    if (countOnes == 3) newBoard[i][j] = 1;
                } 
                else {
                    if (countOnes == 2 || countOnes == 3) newBoard[i][j] = 1;
                }
            }
        }

        board = newBoard;
    }
};

int main() {
    Solution solution;

    // Test case
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Original board:" << endl;
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    solution.gameOfLife(board);

    cout << "\nBoard after applying Game of Life rules:" << endl;
    for (const auto& row : board) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
}