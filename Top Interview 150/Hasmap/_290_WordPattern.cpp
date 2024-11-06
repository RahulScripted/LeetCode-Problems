// Given a pattern and a string s, find if s follows the same pattern. Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically: Each letter in pattern maps to exactly one unique word in s. Each unique word in s maps to exactly one letter in pattern. No two letters map to the same word, and no two words map to the same letter.






#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        
        while (iss >> word) words.push_back(word);
        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> charToWord;
        unordered_set<string> seenWords;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const string& w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } 
            else {
                if (seenWords.count(w)) return false;
                charToWord[c] = w;
                seenWords.insert(w); 
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    bool result1 = solution.wordPattern(pattern1, s1);
    cout << "Pattern \"" << pattern1 << "\" and string \"" << s1 << "\" match? " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    bool result2 = solution.wordPattern(pattern2, s2);
    cout << "Pattern \"" << pattern2 << "\" and string \"" << s2 << "\" match? " << (result2 ? "Yes" : "No") << endl;

    // Test case 3
    string pattern3 = "aaaa";
    string s3 = "dog dog dog dog";
    bool result3 = solution.wordPattern(pattern3, s3);
    cout << "Pattern \"" << pattern3 << "\" and string \"" << s3 << "\" match? " << (result3 ? "Yes" : "No") << endl;

    // Test case 4
    string pattern4 = "abba";
    string s4 = "dog dog dog dog";
    bool result4 = solution.wordPattern(pattern4, s4);
    cout << "Pattern \"" << pattern4 << "\" and string \"" << s4 << "\" match? " << (result4 ? "Yes" : "No") << endl;

    return 0;
}W