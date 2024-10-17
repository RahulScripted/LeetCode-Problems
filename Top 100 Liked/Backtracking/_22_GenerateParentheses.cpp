// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s);
            return;
        }

        if (openP < n) dfs(openP + 1, closeP, s + "(", n, res);
        if (closeP < openP) dfs(openP, closeP + 1, s + ")", n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;   
    }
};

int main() {
    Solution solution;

    // Test case 1: n = 3
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":" << endl;
    for (const string& s : result) cout << s << endl;


    // Test case 2: n = 2
    n = 2;
    result = solution.generateParenthesis(n);

    cout << "\nGenerated Parentheses for n = " << n << ":" << endl;
    for (const string& s : result) cout << s << endl;


    // Test case 3: n = 1
    n = 1;
    result = solution.generateParenthesis(n);

    cout << "\nGenerated Parentheses for n = " << n << ":" << endl;
    for (const string& s : result) cout << s << endl;
}