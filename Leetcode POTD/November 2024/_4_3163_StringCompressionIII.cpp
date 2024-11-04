// Given a string word, compress it using the following algorithm - Begin with an empty string comp. While word is not empty, use the following operation:

// 1.  Remove a maximum length prefix of word made of a single character c repeating at most 9 times.

// 2.  Append the length of the prefix followed by c to comp.

// Return the string comp.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;

        while (i < word.size()) {
            char c = word[i];
            int count = 0;
            while (i < word.size() && word[i] == c && count < 9) {
                i++;
                count++;
            }
            comp += to_string(count) + c;
        }

        return comp;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string word = "leetcode";
    cout<<"Result : "<<solve.compressedString(word)<<endl;
}