// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.





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
    vector<int> ans;
    void f(TreeNode* root) {
        if (root == NULL) return;
        f(root->left);
        ans.push_back(root->val);
        f(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        f(root);
        return ans[k - 1];
    }
};

// Create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

int main() {
    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);

    Solution sol;
    int k = 3;
    cout << k << "rd smallest element in the BST: " << sol.kthSmallest(root, k) << endl;

    return 0;
}