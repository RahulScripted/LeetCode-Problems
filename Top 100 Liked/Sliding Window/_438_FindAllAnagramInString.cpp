// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        if (m > n) return {};
        
        vector<int> res, cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < m; i++) {
            cnt1[s[i] - 'a']++;
            cnt2[p[i] - 'a']++;
        }

        int i = 0, j = m;
        if (cnt1 == cnt2) res.push_back(0);

        while (j < n) {
            cnt1[s[i] - 'a']--;
            cnt1[s[j] - 'a']++;
            i++;
            j++;
            if (cnt1 == cnt2) res.push_back(i);
        }

        return res;
    }
};

// Helper function to print the result
void printVector(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1: s = "cbaebabacd", p = "abc"
    string s1 = "cbaebabacd";
    string p1 = "abc";
    cout << "Test case 1 - Indices of anagrams of '" << p1 << "' in '" << s1 << "': ";
    vector<int> result1 = sol.findAnagrams(s1, p1);
    printVector(result1);

    // Test case 2: s = "abab", p = "ab"
    string s2 = "abab";
    string p2 = "ab";
    cout << "Test case 2 - Indices of anagrams of '" << p2 << "' in '" << s2 << "': ";
    vector<int> result2 = sol.findAnagrams(s2, p2);
    printVector(result2);

    return 0;
}