// A string s is called happy if it satisfies the following conditions:

// 1.  s only contains the letters 'a', 'b', and 'c'.

// 2.  s does not contain any of "aaa", "bbb", or "ccc" as a substring.

// 3.  s contains at most a occurrences of the letter 'a'.

// 4.  s contains at most b occurrences of the letter 'b'.

// 5.  s contains at most c occurrences of the letter 'c'.


// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "". A substring is a contiguous sequence of characters within a string.





#include <iostream>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int currA = 0, currB = 0, currC = 0;
        int maxLen = a + b + c, i = 0;
        string result; // Using std::string instead of StringBuilder
        
        while (i < maxLen) {
            if ((currA != 2 && a >= b && a >= c) || (a > 0 && (currB == 2 || currC == 2))) {
                result += 'a';
                currA++;
                currB = 0;
                currC = 0;
                a--;
            } 
            else if ((currB != 2 && b >= a && b >= c) || (b > 0 && (currA == 2 || currC == 2))) {
                result += 'b';
                currB++;
                currA = 0;
                currC = 0;
                b--;
            } 
            else if ((currC != 2 && c >= a && c >= b) || (c > 0 && (currA == 2 || currB == 2))) {
                result += 'c';
                currC++;
                currA = 0;
                currB = 0;
                c--;
            }
            i++;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    int a, b, c;
    cout << "Enter the count for a: ";
    cin >> a;
    cout << "Enter the count for b: ";
    cin >> b;
    cout << "Enter the count for c: ";
    cin >> c;

    string result = sol.longestDiverseString(a, b, c);
    cout << "Longest diverse string: " << result << endl;
}