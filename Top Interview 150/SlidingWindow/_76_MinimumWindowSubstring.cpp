// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "". The test-cases will be generated such that the answer is unique.





#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        for (char c : t) map[c]++;

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) count--;

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) count++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution solution;
    string result = solution.minWindow(s, t);

    cout << "The minimum window substring is: " << result << endl;

    return 0;
}