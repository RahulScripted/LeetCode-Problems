// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum. The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).




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
    int number(TreeNode* root, long long int currsum, int targetSum) {
        if (root == NULL) return 0;
        currsum += root->val;
        int ans = 0;
        if (targetSum == currsum) ans++;
        return ans + number(root->left, currsum, targetSum) + number(root->right, currsum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        return number(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(-3);
    root->left->left = newNode(3);
    root->left->right = newNode(2);
    root->right->right = newNode(11);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(-2);
    root->left->right->right = newNode(1);

    Solution sol;
    int targetSum = 8;
    int result = sol.pathSum(root, targetSum);

    cout << "Number of paths with sum " << targetSum << ": " << result << endl;
}