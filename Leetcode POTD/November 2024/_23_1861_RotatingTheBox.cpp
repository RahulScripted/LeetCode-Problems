// You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

// 1.  A stone '#'

// 2.  A stationary obstacle '*'

// 3.  Empty '.'

// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions. It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box. Return an n x m matrix representing the box after the rotation described above.






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        for (auto& row : box) {
            int dropPos = n - 1;
            
            for (int currPos = n - 1; currPos >= 0; currPos--) {
                if (row[currPos] == '*') {
                    dropPos = currPos - 1;
                }
                else if (row[currPos] == '#') {
                    swap(row[dropPos], row[currPos]);
                    dropPos--;
                }
            }
        }
        
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> box = {
        {'#', '.', '#'},
        {'#', '#', '*'},
        {'.', '#', '.'}
    };

    vector<vector<char>> rotatedBox = solution.rotateTheBox(box);
    cout << "Rotated box:" << endl;
    for (const auto& row : rotatedBox) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }
}