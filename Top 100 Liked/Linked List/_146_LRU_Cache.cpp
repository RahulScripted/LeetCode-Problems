// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache. Implement the LRUCache class:

// 1.  LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

// 2.  int get(int key) Return the value of the key if the key exists, otherwise return -1.

// 3.  void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// 4.  The functions get and put must each run in O(1) average time complexity.





#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> m;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size;

    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node *p) {
        Node *pre = p->prev;
        Node *nex = p->next;
        pre->next = nex;
        nex->prev = pre;
    }

    void addNode(Node *newnode) {
        Node *temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        Node *p = m[key];
        deleteNode(p);
        addNode(p);
        m[key] = head->next;
        return head->next->val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *c = m[key];
            deleteNode(c);
            c->val = value;
            addNode(c);
            m[key] = head->next;
        } 
        else {
            if (m.size() == size) {
                Node *prev = tail->prev;
                deleteNode(prev);
                m.erase(prev->key);
            }
            Node *l = new Node(key, value);
            addNode(l);
            m[key] = head->next;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1); 
    cache.put(2, 2);
    
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl; 
    
    cache.put(4, 4);  
    
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}