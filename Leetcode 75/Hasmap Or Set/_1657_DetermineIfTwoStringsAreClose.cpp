// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.





#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if (str1.length() != str2.length()) return false;

        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < str1.length(); i++) {
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }

        for (auto x : mp1) {
            char ch = x.first;
            if (mp2.find(ch) == mp2.end()) return false;
        }

        unordered_map<int, int> h1, h2;
        for (auto x : mp1) {
            int freq = x.second;
            h1[freq]++;
        }
        for (auto x : mp2) {
            int freq = x.second;
            h2[freq]++;
        }

        // comparing h1 and h2 maps
        for (auto x : h1) {
            int key = x.first;
            if (h2.find(key) == h2.end()) return false;
            if (h1[key] != h2[key]) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    if (solution.closeStrings(str1, str2)) cout << "The strings are close." << endl;
    else cout << "The strings are not close." << endl;
}