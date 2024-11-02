// Given a string sentence, return true if it is circular. Otherwise, return false.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence[0] != sentence[n-1]) return false;

        for(int i=1; i<n-1; i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1]) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "leetcode exercises sound delightful";
    if(solve.isCircularSentence(s)) cout<<"Circular sentence"<<endl;
    else cout<<"Not a circular sentence"<<endl;

    // 2nd Example
    s = "Leetcode is cool";
    if(solve.isCircularSentence(s)) cout<<"Circular sentence"<<endl;
    else cout<<"Not a circular sentence"<<endl;
}