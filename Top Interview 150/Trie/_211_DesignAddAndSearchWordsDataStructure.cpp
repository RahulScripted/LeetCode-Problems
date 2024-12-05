// Design a data structure that supports adding new words and finding if a string matches any previously added string. Implement the WordDictionary class:

// 1.  WordDictionary() Initializes the object.

// 2.  void addWord(word) Adds word to the data structure, it can be matched later.

// 3.  bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.





#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WordDictionary {
    vector<WordDictionary*> children;
    bool isEndOfWord;
public:
    // Initialize 
    WordDictionary() : isEndOfWord(false) {
        children = vector<WordDictionary*>(26, nullptr);
    }

    // Adds a word 
    void addWord(string word) {
        WordDictionary* curr = this;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr)
                curr->children[c - 'a'] = new WordDictionary();
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        WordDictionary* curr = this;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (auto child : curr->children)
                    if (child && child->search(word.substr(i + 1))) return true;
                return false;
            }
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        }
        return curr && curr->isEndOfWord;
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    cout << (wordDictionary.search("pad") ? "True" : "False") << endl;
    
    cout << (wordDictionary.search("bad") ? "True" : "False") << endl; 

    cout << (wordDictionary.search(".ad") ? "True" : "False") << endl; 

    cout << (wordDictionary.search("b..") ? "True" : "False") << endl;
}