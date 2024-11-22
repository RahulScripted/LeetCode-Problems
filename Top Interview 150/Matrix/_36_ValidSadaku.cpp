// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// 1.  Each row must contain the digits 1-9 without repetition.

// 2.  Each column must contain the digits 1-9 without repetition.

// 3.  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.





#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                char value = board[r][c];
                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value)) {
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;        
    }
};

int main() {
    Solution solution;

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Is the Sudoku board valid? " << (solution.isValidSudoku(board) ? "Yes" : "No") << endl;

    board[0][0] = '8';
    cout << "Is the modified Sudoku board valid? " << (solution.isValidSudoku(board) ? "Yes" : "No") << endl;
}