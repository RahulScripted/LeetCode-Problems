// Given a string s, find the length of the longest substring without repeating characters.

 



#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } 
            else {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        
        return maxLength;

        // Using unorder map
        // int n = s.length();
        // int maxLength = 0;
        // unordered_map<char, int> charMap;
        // int left = 0;
        
        // for (int right = 0; right < n; right++) {
        //     if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
        //         charMap[s[right]] = right;
        //         maxLength = max(maxLength, right - left + 1);
        //     } 
        //     else {
        //         left = charMap[s[right]] + 1;
        //         charMap[s[right]] = right;
        //     }
        // }
        
        // return maxLength;
    }
};

int main() {
    string s = "abcabcbb";  

    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);

    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}