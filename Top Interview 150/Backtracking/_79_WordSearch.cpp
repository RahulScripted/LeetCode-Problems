// Given an m x n grid of characters board and a string word, return true if word exists in the grid.





#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_set<string> visited;

        auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
            if (k == word.length()) return true;
            if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(to_string(r) + "," + to_string(c)) || board[r][c] != word[k]) return false;

            visited.insert(to_string(r) + "," + to_string(c));
            bool res = dfs(r + 1, c, k + 1, dfs) || dfs(r - 1, c, k + 1, dfs) || dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
            visited.erase(to_string(r) + "," + to_string(c));
            return res;
        };

        unordered_map<char, int> count;
        for (char c : word) count[c]++;

        if (count[word[0]] > count[word.back()]) reverse(word.begin(), word.end());
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0, dfs)) return true;
            }
        }

        return false;        
    }
};

int main() {
    Solution solution;
    
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    
    bool result = solution.exist(board, word);
    cout << "Word exists in board: " << (result ? "Yes" : "No") << endl;

    return 0;
}