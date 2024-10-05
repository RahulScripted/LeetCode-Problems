// Given a string s, reverse only all the vowels in the string and return it. The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        else return false;
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isVowel(s[l])) ++l;
            while (l < r && !isVowel(s[r])) --r;
            swap(s[l++], s[r--]);
        }

        return s;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "IceCreAm";
    cout<<"Before reversing vowels from string : "<<s<<endl;
    cout<<"After reversing vowels from string : "<<solve.reverseVowels(s)<<endl;
}