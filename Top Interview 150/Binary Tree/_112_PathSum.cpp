// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.





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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) return targetSum == root->val;
        
        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);
        
        return left_sum || right_sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    Solution solution;

    // Test case 1
    int targetSum1 = 22;
    cout << "Test 1: " << (solution.hasPathSum(root, targetSum1) ? "True" : "False") << endl;

    // Test case 2
    int targetSum2 = 26;
    cout << "Test 2: " << (solution.hasPathSum(root, targetSum2) ? "True" : "False") << endl;

    // Test case 3
    int targetSum3 = 18;
    cout << "Test 3: " << (solution.hasPathSum(root, targetSum3) ? "True" : "False") << endl;

    // Test case 4
    int targetSum4 = 5;
    cout << "Test 4: " << (solution.hasPathSum(root, targetSum4) ? "True" : "False") << endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->right->left;
    delete root->right->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}