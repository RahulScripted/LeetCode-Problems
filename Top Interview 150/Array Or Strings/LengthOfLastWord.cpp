// Given a string s consisting of words and spaces, return the length of the last word in the string. A word is a maximal substring consisting of non-space characters only.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        bool endingWithSpace = false;
        for(int i = (n - 1);i >= 0;i--){
            if(s[i] != ' '){
                count++;
                endingWithSpace = true;
            }
            else if(endingWithSpace) break;
        }
        return count;
    }
};

int main(){
    Solution solve;

    // 1st example
    string s = "Hello World";
    cout<<"Length of last word : "<<solve.lengthOfLastWord(s)<<endl;

    // 2nd example
    s = "   fly me   to   the moon  ";
    cout<<"Length of last word : "<<solve.lengthOfLastWord(s)<<endl;
}