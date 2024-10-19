// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order. A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.






#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void backtrack(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digitToLetters) {
        if (idx == digits.length()) {
            res.push_back(comb);
            return;
        }
        
        string letters = digitToLetters.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
        }
    }   

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        backtrack(digits, 0, "", res, digitToLetters);
        return res;        
    }
};

int main() {
    Solution sol;
    string digits;

    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);

    cout << "Letter combinations:\n";
    for (const string& combination : result) cout << combination << endl;
}