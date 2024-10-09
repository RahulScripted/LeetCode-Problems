// Given an integer numRows, return the first numRows of Pascal's triangle.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Recursion Solution
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        
        for (int i = 1; i < numRows - 1; i++) 
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        
        prevRows.push_back(newRow);
        return prevRows;

        // DP Solution
        // vector<vector<int>> ans;

        // for (int i = 0; i < numRows; ++i)
        // ans.push_back(vector<int>(i + 1, 1));

        // for (int i = 2; i < numRows; ++i){
        //     for (int j = 1; j < ans[i].size() - 1; ++j){
        //         ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        //     }   
        // }

        // return ans;
    }
};

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;

    int numRows = 5;
    vector<vector<int>> triangle = sol.generate(numRows);
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    printTriangle(triangle);
}