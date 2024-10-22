// You are given the root of a binary tree. A ZigZag path for a binary tree is defined as follow:

// 1.  Choose any node in the binary tree and a direction (right or left).

// 2.  If the current direction is right, move to the right child of the current node; otherwise, move to the left child.

// 3.  Change the direction from right to left or from left to right.

// 4.  Repeat the second and third steps until you can't move in the tree.


// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0). Return the longest ZigZag path contained in that tree.






#include <iostream>
#include <algorithm>
#include <utility>

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
    pair<int, int> f(TreeNode* root, int &ans) {
        if (!root) return {0, 0};
        if (!root->left && !root->right) return {0, 0};

        pair<int, int> ltemp = f(root->left, ans), rtemp = f(root->right, ans);
        int lans = 0, rans = 0;
        if (root->left) lans = 1 + ltemp.second;
        if (root->right) rans = 1 + rtemp.first;

        ans = max(ans, max(lans, rans));

        return {lans, rans};
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        f(root, ans);
        return ans;
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    return root;
}

int main() {
    TreeNode* root = createTree();
    Solution solution;
    int result = solution.longestZigZag(root);
    cout << "The longest ZigZag path is: " << result << endl;
}