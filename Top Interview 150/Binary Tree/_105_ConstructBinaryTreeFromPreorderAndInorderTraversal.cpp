// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.





#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderQueue(preorder.begin(), preorder.end());
        return build(preorderQueue, inorder);        
    }

private:
    TreeNode* build(deque<int>& preorder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int val = preorder.front();
            preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), val);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(val);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
            vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preorder, leftInorder);
            root->right = build(preorder, rightInorder);

            return root;
        }

        return nullptr;
    }    
};

// Print inorder traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Input preorder and inorder vectors
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Create an instance of the solution class
    Solution solution;

    // Build the tree
    TreeNode* root = solution.buildTree(preorder, inorder);

    // Output the inorder traversal of the constructed tree to verify
    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}