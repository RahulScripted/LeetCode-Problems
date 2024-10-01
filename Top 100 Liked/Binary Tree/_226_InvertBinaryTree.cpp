// Given the root of a binary tree, invert the tree, and return its root.




#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// Function to print a binary tree in level order
void printTree(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree: ";
    printTree(root);

    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);
    cout << "Inverted tree: ";
    printTree(invertedRoot);
}
