// Given a m * n matrix of ones and zeros, return how many square sub-matrices have all ones.

 



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         // Get dimensions of the matrix
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns
        
        // Create a DP table with same dimensions as matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Variable to store total count of squares
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];  
        }
        
        for (int j = 1; j < m; j++) {
            dp[0][j] = matrix[0][j];
            ans += dp[0][j];
        }
        
        // Fill the DP table for remaining cells
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 1) dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                // Add current cell's value to total count
                ans += dp[i][j];
            }
        }
        
        // Return total count of squares
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case: Define a sample matrix
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    
    int result = solution.countSquares(matrix);
    cout << "Total number of square sub-matrices with all 1s: " << result << endl;
}
