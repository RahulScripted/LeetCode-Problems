// For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees. A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations. Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

 



#include <iostream>
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
    bool checker(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2 || node1->val != node2->val) return false;

        return (checker(node1->left, node2->left) || checker(node1->left, node2->right)) && 
               (checker(node1->right, node2->right) || checker(node1->right, node2->left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return checker(root1, root2);
    }
};

int main() {
    // Create two test binary trees
    TreeNode* root1 = new TreeNode(1, 
                      new TreeNode(2, 
                      new TreeNode(4), 
                      new TreeNode(5)), 
                      new TreeNode(3));
                            
    TreeNode* root2 = new TreeNode(1, 
                      new TreeNode(3), 
                      new TreeNode(2, 
                      new TreeNode(4), 
                      new TreeNode(5)));

    Solution sol;
    bool result = sol.flipEquiv(root1, root2);

    cout << (result ? "The trees are flip equivalent." : "The trees are NOT flip equivalent.") << endl;

    // Clean up memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}