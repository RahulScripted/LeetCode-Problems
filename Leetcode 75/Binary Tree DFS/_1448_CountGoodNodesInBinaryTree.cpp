// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X. Return the number of good nodes in the binary tree.





#include <iostream>
#include <climits> 
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
    int traverse(TreeNode* root, int val) {
        if (root == NULL) return 0;
        int temp = 0;
        if (root->val >= val) temp = 1;

        val = max(val, root->val);
        return temp + traverse(root->right, val) + traverse(root->left, val);
    }

    int goodNodes(TreeNode* root,int mx = INT_MIN) {
        return traverse(root, INT_MIN);
    }
};

// Helper function to create a new TreeNode
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    Solution solution;
    
    TreeNode* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->right->left = createNode(1);
    root->right->right = createNode(5);

    // Test the goodNodes function
    cout << "Number of good nodes: " << solution.goodNodes(root) << endl;
    
    return 0;
}