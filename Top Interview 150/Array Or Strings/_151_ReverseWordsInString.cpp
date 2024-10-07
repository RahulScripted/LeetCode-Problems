// Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseWords(string& s, int n) {
        int i = 0;
        int j = 0;

        while (i < n) {
            while (i < j || i < n && s[i] == ' ')  ++i;
            while (j < i || j < n && s[j] != ' ')  ++j;
            reverse(s.begin() + i, s.begin() + j);  
        }
    }

    string cleanSpaces(string& s, int n) {
        int i = 0;
        int j = 0;

        while (j < n) {
            while (j < n && s[j] == ' ')  ++j;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            while (j < n && s[j] == ' ') ++j;
            if (j < n) s[i++] = ' ';
        }
        return s.substr(0, i);
    }
    string reverseWords(string s) {
        reverse(s.begin(),s.end());  
        reverseWords(s, s.length());
        return cleanSpaces(s, s.length());
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "the sky is blue";
    cout<<"Reverse will be : "<<solve.reverseWords(s)<<endl;
}