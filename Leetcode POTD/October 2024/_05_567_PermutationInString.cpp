// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise. In other words, return true if one of s1's permutations is the substring of s2.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false; // Base Case
        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        // Count frequencies of s1 and the first window in s2
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Slide the window over s2
        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (s1Count == s2Count) return true;
            // Update the window
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }

        // Check the last window
        return s1Count == s2Count;
    }
};


int main(){
    Solution solve;

    // 1st Example
    string s1 = "ab";
    string s2 = "eidbaooo";
    solve.checkInclusion(s1,s2) == true? cout<<s1<<" is a permutation of "<<s2<<endl : cout<<s1<<" is not a permutation of "<<s2<<endl;

    // 1st Example
    s1 = "ab";
    s2 = "eidbooao";
    solve.checkInclusion(s1,s2) == true? cout<<s1<<" is a permutation of "<<s2<<endl : cout<<s1<<" is not a permutation of "<<s2<<endl;
}