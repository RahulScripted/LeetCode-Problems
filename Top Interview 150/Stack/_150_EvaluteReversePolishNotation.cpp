// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation. Evaluate the expression. Return an integer that represents the value of the expression.





#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c : tokens) {
            if (c == "+") {
                int second = st.top(); 
                st.pop();
                int first = st.top(); 
                st.pop();
                st.push(first + second);
            } 
            else if (c == "-") {
                int second = st.top();
                st.pop();
                int first = st.top(); 
                st.pop();
                st.push(first - second);
            } 
            else if (c == "*") {
                int second = st.top(); 
                st.pop();
                int first = st.top(); 
                st.pop();
                st.push(first * second);
            } 
            else if (c == "/") {
                int second = st.top(); 
                st.pop();
                int first = st.top(); 
                st.pop();
                st.push(first / second);
            } 
            else st.push(stoi(c));
        }
        return st.top();        
    }
};

int main() {
    Solution solution;
    
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = solution.evalRPN(tokens);
    cout << "The result of the RPN expression is: " << result << endl;
}