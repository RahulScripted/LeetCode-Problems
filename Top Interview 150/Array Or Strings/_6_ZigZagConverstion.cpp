// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows: string convert(string s, int numRows);





#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;

        int idx = 0, d = 1;
        vector<vector<char>> rows(numRows);

        for (char c : s) {
            rows[idx].push_back(c);
            if (idx == 0) d = 1;
            else if (idx == numRows - 1) d = -1;
            idx += d;
        }

        string result;
        for (const auto& row : rows) {
            for (char c : row) result += c;
        }

        return result;        
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Result for s1 with numRows1: " << solution.convert(s1, numRows1) << endl;

    // Test case 2
    string s2 = "HELLOZIGZAG";
    int numRows2 = 4;
    cout << "Result for s2 with numRows2: " << solution.convert(s2, numRows2) << endl;

    // Test case 3
    string s3 = "ABCD";
    int numRows3 = 2;
    cout << "Result for s3 with numRows3: " << solution.convert(s3, numRows3) << endl;

    return 0;
}