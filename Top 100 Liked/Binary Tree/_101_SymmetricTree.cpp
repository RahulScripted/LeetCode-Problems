// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).




#include <iostream>
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

bool helper(TreeNode* node1,TreeNode* node2){
    if(node1 == NULL && node2 == NULL) return true;
   if(node1 == NULL || node2 == NULL) return false;
    return node1->val == node2->val && helper(node1->left,node2->right) && helper(node1->right,node2->left);
}
bool isSymmetric(TreeNode* root) {
    return helper(root->left,root->right);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if(isSymmetric(root)) cout<<"Yes, Symmetric"<<endl;
    else cout<<"No, not Symmetric"<<endl;
}