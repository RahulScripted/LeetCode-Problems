// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:

// 1.  Open brackets must be closed by the same type of brackets.

// 2.  Open brackets must be closed in the correct order.

// 3.  Every close bracket has a corresponding open bracket of the same type.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Create Stack
        stack<char>st;

        // Run Loop
        for(int i = 0;i < s.length();i++){
            // If Opening bracket then push in stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);

            // If close bracket 
            else{
                // Check the top element is same type of opening bracket or not
                if(st.empty() || 
                (s[i] == ')' && st.top() != '(') || 
                (s[i] == '}' && st.top() != '{') || 
                (s[i] == ']' && st.top() != '[')) return false; // Return false

                else st.pop(); // Else pop
            }
        }

        // Check whether the stack is empty or not 
        return st.empty();
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "(]";
    if(solve.isValid(s)) cout<<s<<" -> "<<"Valid"<<endl;
    else cout<<s<<" -> "<<"Not valid"<<endl;

    // 2nd Example
    s = "([])";
    if(solve.isValid(s)) cout<<s<<" -> "<<"Valid"<<endl;
    else cout<<s<<" -> "<<"Not valid"<<endl;
}