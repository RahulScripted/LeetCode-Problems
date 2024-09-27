// You are given the root of a binary search tree (BST) and an integer val. Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.




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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;
        else if(root -> val > val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
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

void Display(TreeNode* &a){
    // Base Case
    if(a == NULL) return;
    cout<<a->val<<" ";
    Display(a->left);
    Display(a->right);
}

int main() {
    Solution solution;
    vector<int> data = {4,2,7,1,3};
    TreeNode* root = buildTreeFromQueue(data);
    int val;
    cout<<"Enter the value you want to find : ";
    cin>>val;
    TreeNode*temp = solution.searchBST(root,val);
    Display(temp);
}