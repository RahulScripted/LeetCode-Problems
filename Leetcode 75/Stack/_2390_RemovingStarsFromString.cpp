// You are given a string s, which contains stars *. In one operation, you can:

// 1.  Choose a star in s.

// 2.  Remove the closest non-star character to its left, as well as remove the star itself.

// Return the string after all stars have been removed.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        // Without Stack
        string ans;
        for (const char c : s){
            if (c == '*') ans.pop_back();
            else ans.push_back(c);
        }
        return ans;

        // With Stack
        // stack<char>st;
        // int n = s.length();
        // for(int i = 0;i < n;i++){
        //     if(s[i] == '*') st.pop();
        //     else st.push(s[i]);
        // }
        // string ans = "";
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans; 
    }
};

int main(){
    Solution solve;

    // 1st example
    string s = "leet**cod*e";
    cout<<"String after all stars have been removed will be : "<<solve.removeStars(s)<<endl;

    // 2nd example
    s = "erase*****";
    cout<<"String after all stars have been removed will be : "<<solve.removeStars(s)<<endl;
}