// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.





#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int number = 0;
        int signValue = 1;
        int result = 0;
        stack<int> operationsStack;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += number * signValue;
                signValue = (c == '-') ? -1 : 1;
                number = 0;
            } else if (c == '(') {
                operationsStack.push(result);
                operationsStack.push(signValue);
                result = 0;
                signValue = 1;
            } else if (c == ')') {
                result += signValue * number;
                result *= operationsStack.top();
                operationsStack.pop();
                result += operationsStack.top();
                operationsStack.pop();
                number = 0;
            }
        }

        return result + number * signValue;
    }
};

int main() {
    Solution solution;

    string expression;
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);
    int result = solution.calculate(expression);
    cout << "The result is: " << result << endl;
}