// Given a string s, return the maximum number of unique substrings that the given string can be split into. You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique. A substring is a contiguous sequence of characters within a string.





#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int backtrack(int start, const string& s, unordered_set<string>& seen) {
        if (start == s.size()) return 0;

        int maxSplits = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
                seen.erase(substring);
            }
        }
        return maxSplits;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = solution.maxUniqueSplit(s);
    cout << "Maximum number of unique splits: " << result << endl;

    return 0;
}