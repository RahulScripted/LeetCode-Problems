// Given the root of a binary tree, return the inorder traversal of its nodes' values.




#include <iostream>
#include <vector>
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

class Solution {
public:
    void helper(TreeNode* root,vector<int>&ans){
        if(root == NULL) return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
    }
};


int main() {
    Solution solve;

    // Tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(3);

    vector<int>ans = solve.inorderTraversal(root);
    cout<<"Inorder traversal : ";
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}