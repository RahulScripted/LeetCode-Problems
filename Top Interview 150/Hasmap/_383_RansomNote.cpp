// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise. Each letter in magazine can only be used once in ransomNote.





#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Map Solution
        unordered_map<char, int> magaHash;
        for (char c : magazine) magaHash[c]++;

        for (char c : ransomNote) {
            if (magaHash[c] <= 0) return false;
            magaHash[c]--;
        }

        return true;

         // Set Solution
        // if (ransomNote.length() > magazine.length()) return false;
        // unordered_set<char> ransomSet(ransomNote.begin(), ransomNote.end());

        // for (char c : ransomSet) {
        //     if (countOccurrences(magazine, c) < countOccurrences(ransomNote, c)) return false;
        // }
        // return true;
    }
};

int main() {
    Solution solution;

    // Define sample ransom note and magazine
    string ransomNote = "aa";
    string magazine = "aab";

    // Call the function with sample input
    bool result = solution.canConstruct(ransomNote, magazine);

    // Print the result
    if (result) cout << "Yes, it is possible to construct the ransom note from the magazine." << endl;
    else cout << "No, it is not possible to construct the ransom note from the magazine." << endl;
}