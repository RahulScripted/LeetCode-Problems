// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'. A string is called balanced if and only if:

// 1.  It is the empty string, or

// 2.  It can be written as AB, where both A and B are balanced strings, or

// 3.  It can be written as [C], where C is a balanced string.

// You may swap the brackets at any two indices any number of times. Return the minimum number of swaps to make s balanced.






#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        // Approach 3
        int lb=0;
        int moves=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==']'){
                if(lb==0){
                    moves++;
                    lb++;
                }
                else lb--;
            }
            else lb++;
        }

        return moves;

        // Approach 2
        // stack<char> st;
        // int minCount = 0;

        // for (char ch:s) {
        //     if (ch == '[') st.push(ch);
        //     else {
        //         if (!st.empty() && st.top() == '[') st.pop();
        //         else st.push(ch);
        //     }
        // }

        // while (!st.empty()) {
        //     char a = st.top(); 
        //     st.pop();
        //     char b = st.top(); 
        //     st.pop();

        //     if (a==b) minCount++;
        //     else minCount+=2;
        // }
        // return minCount/2;

        // Approach 1
        // int sz = 0;
        // int n = s.size();
        // for (int i = 0; i < n; i++) {
        //     char ch = s[i];
        //     if (ch == '[') sz++;
        //     else if (sz > 0) sz--;
        // }
        // return (sz + 1) / 2;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "][][";
    cout<<"Minimum swaps required : "<<solve.minSwaps(s)<<endl;

    // 2nd Example
    s = "]]][[[";
    cout<<"Minimum swaps required : "<<solve.minSwaps(s)<<endl;
}