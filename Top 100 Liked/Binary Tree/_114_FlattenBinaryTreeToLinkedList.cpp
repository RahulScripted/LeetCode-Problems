// Given the root of a binary tree, flatten the tree into a "linked list": The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null. The "linked list" should be in the same order as a pre-order traversal of the binary tree.





#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode* last = current->left;
                while (last->right != nullptr) last = last->right;

                last->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }
};

// Helper function to create a binary tree node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Print the flattened tree
void printFlattenedTree(TreeNode* root) {
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    cout << "Original tree in preorder (flattened form): ";
    printFlattenedTree(root); 

    // Call the flatten function
    Solution solution;
    solution.flatten(root);

    // Print the flattened tree
    cout << "Flattened tree: ";
    printFlattenedTree(root); 

    return 0;
}