// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

// 1.   't' that evaluates to true.

// 2.   'f' that evaluates to false.

// 3.   '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.

// 4.   '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

// 5.   '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

// 6.    Given a string expression that represents a boolean expression, return the evaluation of that expression.






#include <iostream>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char currChar : expression) {
            if (currChar == ',' || currChar == '(') continue;  
            if (currChar == 't' || currChar == 'f' || currChar == '!' ||
                currChar == '&' || currChar == '|') {
                st.push(currChar);
            }
            else if (currChar == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if (op == '!')  st.push(hasTrue ? 'f' : 't');
                else if (op == '&') st.push(hasFalse ? 'f' : 't');
                else st.push(hasTrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};

int main() {
    Solution solution;

    // Test case 1
    string expression1 = "|(&(t,f,t),!(t))";
    cout << "Expression: " << expression1 << endl;
    cout << "Result: " << (solution.parseBoolExpr(expression1) ? "true" : "false") << endl;

    // Test case 2
    string expression2 = "&(t,t,t)";
    cout << "Expression: " << expression2 << endl;
    cout << "Result: " << (solution.parseBoolExpr(expression2) ? "true" : "false") << endl;

    // Test case 3
    string expression3 = "!(f)";
    cout << "Expression: " << expression3 << endl;
    cout << "Result: " << (solution.parseBoolExpr(expression3) ? "true" : "false") << endl;
}