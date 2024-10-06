// You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters. Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> split(const string& sentence) {
        vector<string> words;
        istringstream iss(sentence);

        for (string s; iss >> s;) words.push_back(s);
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() == sentence2.length()) return sentence1 == sentence2;

        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        const int m = words1.size();
        const int n = words2.size();
        if (m > n) return areSentencesSimilar(sentence2, sentence1);

        int i = 0;  // words1's index
        while (i < m && words1[i] == words2[i]) ++i;
        while (i < m && words1[i] == words2[i + n - m]) ++i;
        return i == m;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";

    if(solve.areSentencesSimilar(sentence1,sentence2)) cout<<"There are acceptable similarities"<<endl;
    
    else cout<<"There are not any acceptable similarities"<<endl;
}