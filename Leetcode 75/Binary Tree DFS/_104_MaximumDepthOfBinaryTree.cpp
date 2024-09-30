// Given the root of a binary Tree, return its maximum depth. A binary Tree maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.




#include<iostream>
#include<algorithm>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void Display(TreeNode* &a){
    // Base Case
    if(a == NULL) return;
    cout<<a->val<<" ";
    Display(a->left);
    Display(a->right);
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }
};

int main(){
    Solution solve;
    TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(20);
    TreeNode* c = new TreeNode(30);
    TreeNode* d = new TreeNode(0);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(7);
    TreeNode* g = new TreeNode(11);

    // Building connection
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    Display(a);
    cout<<endl<<"Height of the TreeNode : "<<solve.maxDepth(a);
}