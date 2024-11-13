// You are given a string s and an array of strings words. All the strings of words are of the same length.A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated. Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.





#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (const string& word : words) {
            counts[word]++;
        }

        int n = s.length();
        int wordsize = words.size();
        int len = words[0].size();
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int start = i, count = 0;
            unordered_map<string, int> mp;
            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);
                if (counts.find(word) != counts.end()) {
                    mp[word]++;
                    count++;

                    while (mp[word] > counts[word]) {
                        string leftword = s.substr(start, len);
                        mp[leftword]--;
                        count--;
                        start += len;
                    }
                    if (count == wordsize) {
                        ans.push_back(start);
                    }
                } else {
                    mp.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return ans;
    }
};

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution solution;
    vector<int> result = solution.findSubstring(s, words);

    cout << "Starting indices of substring(s): ";
    for (int index : result) cout << index << " ";
    cout << endl;
}