// You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

// 1.  The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.

// 2.  The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.

// Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canChange(string s, string t) {
        const int n = s.size();
        for (int i = 0, j = 0; i < n || j < n; i++, j++) {
            while (i < n && s[i] == '_') i++;
            while (j < n && t[j] == '_') j++;

            if (i < n && j < n) {
                char c = s[i];
                if (c != t[j]) return false;
                if (c == 'L' && i < j) return false;
                if (c == 'R' && i > j) return false;
            } 
            else if (i < n || j < n) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    string s1 = "_L__R__R_";
    string t1 = "L___R__R_";
    cout << (solution.canChange(s1, t1) ? "True" : "False") << endl;

    string s2 = "R_L_";
    string t2 = "__RL";
    cout << (solution.canChange(s2, t2) ? "True" : "False") << endl;

    string s3 = "_R";
    string t3 = "R_";
    cout << (solution.canChange(s3, t3) ? "True" : "False") << endl;
}