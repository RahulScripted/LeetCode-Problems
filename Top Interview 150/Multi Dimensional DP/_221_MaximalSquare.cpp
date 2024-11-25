// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.




#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveBottomUp(vector<vector<char>>& matrix) {
        int n = matrix.size();  
        int m = matrix[0].size();  
        int maxi = 0; 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); 

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    int right = dp[i][j + 1];
                    int diagonal = dp[i + 1][j + 1];
                    int down = dp[i + 1][j];

                    int currSquareSide = 1 + min(right, min(diagonal, down));
                    dp[i][j] = currSquareSide;

                    maxi = max(maxi, currSquareSide);
                }
            }
        }

        return maxi * maxi; 
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        return solveBottomUp(matrix);
    }
};

int main() {
    Solution solution;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = solution.maximalSquare(matrix);
    cout << "The area of the largest square is: " << result << endl;

    return 0;
}