// Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence. Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.






#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 1;
        
        while (stream >> word) {
            if (word.find(searchWord) == 0) return index;
            index++;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string sentence1 = "hello world this is a test";
    string searchWord1 = "wor";
    cout << "Test 1: " << solution.isPrefixOfWord(sentence1, searchWord1) << endl;

    // Test case 2
    string sentence2 = "open the door please";
    string searchWord2 = "the";
    cout << "Test 2: " << solution.isPrefixOfWord(sentence2, searchWord2) << endl;

    // Test case 3
    string sentence3 = "this is an example";
    string searchWord3 = "ex";
    cout << "Test 3: " << solution.isPrefixOfWord(sentence3, searchWord3) << endl;

    // Test case 4
    string sentence4 = "coding is fun";
    string searchWord4 = "run";
    cout << "Test 4: " << solution.isPrefixOfWord(sentence4, searchWord4) << endl;

    return 0;
}