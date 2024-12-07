// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// 1.  Every adjacent pair of words differs by a single letter.

// 2.  Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.

// 3.  sk == endWord

// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.





#include <Bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
    
        if (st.find(endWord) == st.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord); 

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (word == endWord) return steps + 1;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = originalChar; 
            }
        }
        return 0; 
    }
};

int main() {
    Solution solution;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = solution.ladderLength(beginWord, endWord, wordList);
    if (result > 0) cout << "The shortest transformation sequence has length: " << result << endl;
    else cout << "No transformation sequence exists." << endl;
}