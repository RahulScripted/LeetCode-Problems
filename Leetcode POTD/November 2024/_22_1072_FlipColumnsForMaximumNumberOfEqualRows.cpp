// You are given an m x n binary matrix matrix. You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa). Return the maximum number of rows that have all values equal after some number of flips.





#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patFreq;

        for (const auto& row : matrix) { 
            string pattern;
            if (row[0] == 0) {
                for (int bit : row) pattern += to_string(bit);
            } else {
                for (int bit : row) pattern += to_string(bit ^ 1);
            }
            patFreq[pattern]++;
        }

        int maxFreq = 0;
        for (const auto& pair : patFreq) {
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    int result = solution.maxEqualRowsAfterFlips(matrix);
    cout << "Maximum number of equal rows after flips: " << result << endl;
}