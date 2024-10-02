// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence. Two binary trees are considered leaf-similar if their leaf value sequence is the same. Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.




#include <iostream>
#include <vector>
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
    void solve(TreeNode* root, vector<int>& leaf) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) leaf.push_back(root->val);
        solve(root->left, leaf);
        solve(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        solve(root1, leaf1);
        solve(root2, leaf2);
        return leaf1 == leaf2;
    }
};

// Utility function to create a new TreeNode.
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Creating Tree 1
    TreeNode* root1 = newNode(3);
    root1->left = newNode(5);
    root1->right = newNode(1);
    root1->left->left = newNode(6);
    root1->left->right = newNode(2);
    root1->left->right->left = newNode(7);
    root1->left->right->right = newNode(4);
    root1->right->left = newNode(9);
    root1->right->right = newNode(8);

    // Creating Tree 2
    TreeNode* root2 = newNode(3);
    root2->left = newNode(5);
    root2->right = newNode(1);
    root2->left->left = newNode(6);
    root2->left->right = newNode(7);
    root2->right->left = newNode(4);
    root2->right->right = newNode(8);


    Solution solution;
    if (solution.leafSimilar(root1, root2)) cout << "The trees have similar leaf sequences." << endl;
    else cout << "The trees do not have similar leaf sequences." << endl;
}