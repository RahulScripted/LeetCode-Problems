// Given the root of a binary tree, determine if it is a valid binary search tree (BST).



#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root == NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        bool flag = true;
        for(int i = 1;i < ans.size();i++){
            if(ans[i] <= ans[i - 1]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};

TreeNode* buildTreeFromQueue(vector<int> data) {
    if (data.empty() || data[0] == -1) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(data[0]);
    q.push(root);

    int i = 1;
    while (i < data.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Build left child
        if (data[i] != INT_MIN) {
            current->left = new TreeNode(data[i]);
            q.push(current->left);
        }
        i++;

        // Build right child
        if (i < data.size() && data[i] != INT_MIN) {
            current->right = new TreeNode(data[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution solution;
    vector<int> data = {4,2,7,1,3};
    TreeNode* root = buildTreeFromQueue(data);

    if(solution.isValidBST(root)) cout<<"Yes, it's a valid binary search tree"<<endl;
    else cout<<"No, it's not a valid binary search tree"<<endl;
}