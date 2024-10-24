// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker. Implement the Trie class:

// 1.  Trie() Initializes the trie object.

// 2.  void insert(String word) Inserts the string word into the trie.

// 3.  boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.

// 4.  boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.






#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix == false) return p->isWord;
        return true;
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

int main() {
    Trie trie;
    
    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    
    // Search for exact words
    cout << (trie.search("apple") ? "Found 'apple'" : "Did not find 'apple'") << endl;
    cout << (trie.search("app") ? "Found 'app'" : "Did not find 'app'") << endl;
    cout << (trie.search("application") ? "Found 'application'" : "Did not find 'application'") << endl;
    
    // Check for prefixes
    cout << (trie.startsWith("app") ? "'app' is a prefix" : "'app' is not a prefix") << endl;
    cout << (trie.startsWith("bat") ? "'bat' is a prefix" : "'bat' is not a prefix") << endl;
    
    return 0;
}