// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties: Integers in each row are sorted in ascending from left to right. Integers in each column are sorted in ascending from top to bottom.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix[0].size() - 1;

        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] > target) --c;
            else ++r;
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Matrix search for " << target1 << ": " << (sol.searchMatrix(matrix, target1) ? "Found" : "Not found") << endl;

    cout << "Matrix search for " << target2 << ": " << (sol.searchMatrix(matrix, target2) ? "Found" : "Not found") << endl;

    return 0;
}