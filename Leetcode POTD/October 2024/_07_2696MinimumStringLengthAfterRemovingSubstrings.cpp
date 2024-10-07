// You are given a string s consisting only of uppercase English letters. You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s. Return the minimum possible length of the resulting string that you can obtain.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        // Approach 2
        int writeIdx = 0; // Acts like the stack pointer
        for (char currentChar : s) {
            if (writeIdx > 0 && 
                ((s[writeIdx - 1] == 'A' && currentChar == 'B') || 
                 (s[writeIdx - 1] == 'C' && currentChar == 'D'))) {
                writeIdx--; // Remove the last character (pop)
            } 
            else s[writeIdx++] = currentChar;
        }
        return writeIdx; 

        // Approach 1
        // stack<char> stack;

        // for (int i = 0; i < s.length(); i++) {
        //     char cur_char = s[i];

        //     if (stack.empty()) {
        //         stack.push(cur_char);
        //         continue;
        //     }

        //     if (cur_char == 'B' && stack.top() == 'A') stack.pop();
        //     else if (cur_char == 'D' && stack.top() == 'C') stack.pop();
        //     else stack.push(cur_char);
        // }

        // return stack.size();
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "ABFCACDB";
    cout<<"After removing substring minimum length will be : "<<solve.minLength(s)<<endl;
}