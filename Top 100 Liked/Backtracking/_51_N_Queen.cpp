// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.





#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        if (n == 1) {
            results.push_back({"Q"});
            return results;
        }
        if (n == 2 || n == 3) {
            return results;
        }

        vector<int> solution(n, -1);
        solveNQueensRec(n, solution, 0, results);
        return results;
    }

private:
    void solveNQueensRec(int n, vector<int>& solution, int row,
                         vector<vector<string>>& results) {
        if (row == n) {
            vector<string> solutionStr = constructSolutionString(solution);
            results.push_back(solutionStr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValidMove(row, col, solution)) {
                solution[row] = col;
                solveNQueensRec(n, solution, row + 1, results);
                solution[row] = -1; // Backtrack
            }
        }
    }

    bool isValidMove(int proposedRow, int proposedCol,
                     const vector<int>& solution) {
        for (int i = 0; i < proposedRow; i++) {
            int oldRow = i;
            int oldCol = solution[i];
            int diagonalOffset = proposedRow - oldRow;

            if (oldCol == proposedCol ||
                oldCol == proposedCol - diagonalOffset ||
                oldCol == proposedCol + diagonalOffset) {
                return false;
            }
        }
        return true;
    }

    vector<string> constructSolutionString(const vector<int>& solution) {
        vector<string> returnArr(solution.size(), string(solution.size(), '.'));
        for (int i = 0; i < solution.size(); i++) {
            returnArr[i][solution[i]] = 'Q';
        }
        return returnArr;
    }
};

using namespace std;

int main() {
    Solution solution;
    
    int n = 4;
    
    vector<vector<string>> results = solution.solveNQueens(n);
    cout << "All solutions for " << n << "-Queens problem:" << endl;
    for (const auto& board : results) {
        for (const string& row : board) cout << row << endl;
        cout << endl;
    }
}