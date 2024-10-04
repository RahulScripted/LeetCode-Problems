// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.




#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if a node exists in the tree
bool exists(TreeNode* root, TreeNode* target) {
    if (root == NULL) return false;
    if (root == target) return true;
    return exists(root->left, target) || exists(root->right, target);
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //  if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
    //  else if(exists(root->right,p) && exists(root->right,q)) return lowestCommonAncestor(root->right,p,q);
    //  else return root;

    
    // Base Case of 2nd solution
    if (!root || root == p || root == q) return root;

    // Recursively check left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right contain p and q, current node is LCA
    if (left && right) return root;

    // Otherwise, return the non-null node
    return left ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Define nodes for which to find LCA
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) cout << "Lowest Common Ancestor: " << lca->val << endl;
    else cout << "No Common Ancestor found." << endl;
}