// Given a binary tree Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. 





#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* node = root;  

        while (node != nullptr) {
            Node dummy(0); 
            for (Node* needle = &dummy; node; node = node->next) {
                if (node->left != nullptr) {  // Needle the left child.
                    needle->next = node->left;
                    needle = needle->next;
                }
                if (node->right != nullptr) {  // Needle the right child.
                    needle->next = node->right;
                    needle = needle->next;
                }
            }
            node = dummy.next;  
        }

        return root;
    }
};

// Print tree level
void printTreeByLevel(Node* root) {
    while (root != nullptr) {
        Node* current = root;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << "# "; // End of level
        root = root->left; // Move to the next level
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    solution.connect(root);
    cout << "Tree levels using 'next' pointers: ";
    printTreeByLevel(root);
    cout << endl;
}