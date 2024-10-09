// A parentheses string is valid if and only if:

// 1.  It is the empty string

// 2.  It can be written as AB (A concatenated with B), where A and B are valid strings, or

// 3.  It can be written as (A), where A is a valid string.


// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string. Return the minimum number of moves required to make s valid.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        // Greedy Algorithm
        int n = s.length();
        int isOpen = 0,isClose = 0;
        for(char ch : s){
            if(ch == '(') isOpen++;
            else{
                if(isOpen > 0) isOpen--;
                else isClose++;
            }
        }
        return isOpen + isClose;

        // Using Stack
        // stack<char>st;
        // for(const char& ch : s){
        //     bool isPoped = false;
        //     if(!st.empty()){
        //         char top = st.top();
        //         if(ch==')' && top == '('){
        //             st.pop();
        //             isPoped = true;
        //         }
        //     }
        //     if(!isPoped) st.push(ch);
        // }
        // return st.size();
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "())";
    cout<<"Minimum needed : "<<solve.minAddToMakeValid(s)<<endl;

    // 2nd Example
    s = "(((";
    cout<<"Minimum needed : "<<solve.minAddToMakeValid(s)<<endl;
}