// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s. Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.




#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        for (char c : s) count[c - 'a']++;
        if (*min_element(count.begin(), count.end()) < k) return -1;
        
        // Sliding Window
        int res = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'a']--;
            
            while (*min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                l++;
            }
            res = min(res, static_cast<int>(s.length()) - (r - l + 1));
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "aabbcc";
    int k = 2;

    int result = solution.takeCharacters(s, k);
    cout << "Result: " << result << endl;
}