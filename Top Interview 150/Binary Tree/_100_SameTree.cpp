// Given the roots of two binary trees p and q, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.




#include<bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to create a new TreeNode
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Function to create a sample tree for testing
TreeNode* createSampleTree1() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    return root;
}

// Function to create another sample tree for testing
TreeNode* createSampleTree2() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    return root;
}

int main() {
    // Create two sample trees
    TreeNode* tree1 = createSampleTree1();
    TreeNode* tree2 = createSampleTree2();

    // Check if the trees are the same
    Solution solution;
    bool result = solution.isSameTree(tree1, tree2);

    // Output the result
    if (result) cout << "The trees are the same." << endl;
    else cout << "The trees are different." << endl;
}