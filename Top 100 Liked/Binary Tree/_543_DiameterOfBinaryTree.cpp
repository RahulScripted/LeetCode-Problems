// Given the root of a binary tree, return the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root. The length of a path between two nodes is represented by the number of edges between them.




#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to calculate the levels of the tree
int levels(TreeNode* root) {
    // Base Case
    if (root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

// Helper function to calculate the diameter using first approach
void helper(TreeNode* root, int &maxDia) {
    // Base Case
    if (root == NULL) return;
    int dia = levels(root->left) + levels(root->right);
    maxDia = max(maxDia, dia);
    helper(root->left, maxDia);
    helper(root->right, maxDia);
}

// Approach 2 to calculate the diameter
int approach2(TreeNode* root, int &maxDia) {
    // Base Case
    if (root == NULL) return 0;
    int l = 0, r = 0;
    if (root->left) l = approach2(root->left, maxDia);
    if (root->right) r = approach2(root->right, maxDia);
    maxDia = max(maxDia, l + r);
    return 1 + max(l, r);
}

// Calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    // Using approach 2
    int maxDia = 0;
    approach2(root, maxDia);
    return maxDia;
}

// Example Usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of Binary Tree: " << diameterOfBinaryTree(root) << endl;
    return 0;
}