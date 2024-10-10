// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null. Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.




#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Solution class implementing the deep copy logic
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Create new nodes and insert them in between the original nodes
        Node* cur = head;
        while (cur) {
            Node* n = new Node(cur->val);
            n->next = cur->next;
            cur->next = n;
            cur = cur->next->next;
        }

        // Step 2: Assign random pointers for the newly created nodes
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // Step 3: Separate the newly created list from the original list
        cur = head;
        Node* new_head = head->next;
        Node* head2 = head->next;
        while (cur) {
            cur->next = cur->next->next;
            head2->next = head2->next ? head2->next->next : NULL;
            cur = cur->next;
            head2 = head2->next;
        }
        return new_head;
    }
};

// Helper function to print the list
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << "Node val: " << cur->val;
        if (cur->random) {
            cout << ", Random points to: " << cur->random->val;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        cur = cur->next;
    }
}

int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting up random pointers
    head->random = head->next->next;
    head->next->random = head; 

    // Print the original list
    cout << "Original List:" << endl;
    printList(head);

    // Create a solution object and copy the list
    Solution sol;
    Node* copiedList = sol.copyRandomList(head);

    // Print the copied list
    cout << "\nCopied List:" << endl;
    printList(copiedList);

    return 0;
}