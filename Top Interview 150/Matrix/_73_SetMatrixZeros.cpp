// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Constant Space
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = false, flag2 = false;
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0) flag1 = true;
        }

        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0) flag2 = true;
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(flag1 == true){
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        }

        if(flag2 == true){
            for(int j=0; j<m; j++) matrix[0][j] = 0;
        }

        // Has Table
        // int n = matrix.size();
        // int m = matrix[0].size();
        // unordered_set<int> setRows; 
        // unordered_set<int> setColumns; 
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(matrix[i][j] == 0){
        //             setRows.insert(i);
        //             setColumns.insert(j);
        //         }
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(setRows.count(i) > 0 || setColumns.count(j) > 0) matrix[i][j] = 0;
        //     }
        // }

        // Brute-force
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> visited = matrix;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(matrix[i][j] == 0){
        //             for(int k=0; k<m; k++) visited[i][k] = 0;
        //         }
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(matrix[i][j] == 0){
        //             for(int k=0; k<n; k++) visited[k][j] = 0;
        //         }
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++) matrix[i][j] = visited[i][j];
        // }
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test case 1
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    // Test case 2
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    Solution sol;

    cout << "Original Matrix 1:" << endl;
    printMatrix(matrix1);
    sol.setZeroes(matrix1);
    cout << "Modified Matrix 1:" << endl;
    printMatrix(matrix1);

    cout << "\nOriginal Matrix 2:" << endl;
    printMatrix(matrix2);
    sol.setZeroes(matrix2);
    cout << "Modified Matrix 2:" << endl;
    printMatrix(matrix2);

    return 0;
}