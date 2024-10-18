// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else max_len = max(max_len, i - st.top());
            }
        }

        return max_len;
    }
};

int main() {
    Solution solution;
    string s = "(()))())(";

    int result = solution.longestValidParentheses(s);
    cout << "The length of the longest valid parentheses substring is: " << result << endl;
}