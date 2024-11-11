// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.





#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string haystack1 = "hello";
    string needle1 = "ll";
    cout << "Result for haystack1 and needle1: " << solution.strStr(haystack1, needle1) << endl;

    // Test case 2
    string haystack2 = "abcdef";
    string needle2 = "de";
    cout << "Result for haystack2 and needle2: " << solution.strStr(haystack2, needle2) << endl;

    // Test case 3
    string haystack3 = "abcdef";
    string needle3 = "gh";
    cout << "Result for haystack3 and needle3: " << solution.strStr(haystack3, needle3) << endl;

    // Test case 4
    string haystack4 = "aaaaa";
    string needle4 = "bba";
    cout << "Result for haystack4 and needle4: " << solution.strStr(haystack4, needle4) << endl;

    // Test case 5
    string haystack5 = "abcdef";
    string needle5 = "";
    cout << "Result for haystack5 and empty needle: " << solution.strStr(haystack5, needle5) << endl;

    return 0;
}