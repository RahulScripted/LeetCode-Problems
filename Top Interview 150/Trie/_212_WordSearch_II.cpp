// Given an m x n board of characters and a list of strings words, return all words on the board. Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26] = {NULL};
    bool isWord = false;
};

class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    void addWord(TrieNode* cur, string word) {
        for (auto ch : word) {
            if (!cur->child[ch - 'a']) cur->child[ch - 'a'] = new TrieNode();
            cur = cur->child[ch - 'a'];
        }
        cur->isWord = true;
    }

    void dfs(vector<string>& ans, string ds, TrieNode* cur, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        if (!cur) return;
        if (cur->isWord) {
            ans.push_back(ds);
            cur->isWord = false; // Avoid duplicates
        }

        vis[i][j] = true;
        for (int del = 0; del < 4; del++) {
            int next_i = i + dir[del], next_j = j + dir[del + 1];
            if (next_i >= 0 && next_i < board.size() && next_j >= 0 && next_j < board[0].size() && !vis[next_i][next_j] && cur->child[board[next_i][next_j] - 'a']) {
                dfs(ans, ds + board[next_i][next_j], cur->child[board[next_i][next_j] - 'a'], next_i, next_j, board, vis);
            }
        }
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Add all words to the Trie
        for (auto word : words) addWord(trie, word);

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = board[i][j];
                if (trie->child[ch - 'a']) {
                    dfs(ans, string(1, ch), trie->child[ch - 'a'], i, j, board, vis);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<char>> board1 = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words1 = {"oath", "pea", "eat", "rain"};
    vector<string> result1 = solution.findWords(board1, words1);
    cout << "Found words: ";
    for (const auto& word : result1) cout << word << " ";
    cout << endl;

    // Test case 2
    vector<vector<char>> board2 = {
        {'a', 'b'},
        {'c', 'd'}
    };
    vector<string> words2 = {"ab", "cb", "ad", "bd", "ac", "ca", "da", "db", "cd"};
    vector<string> result2 = solution.findWords(board2, words2);
    cout << "Found words: ";
    for (const auto& word : result2) cout << word << " ";
    cout << endl;
}