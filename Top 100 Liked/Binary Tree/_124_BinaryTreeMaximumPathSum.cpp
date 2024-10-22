// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root. The path sum of a path is the sum of the node's values in the path. Given the root of a binary tree, return the maximum path sum of any non-empty path.





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
    int maxi = INT_MIN;
    int sum(TreeNode* root){
        if(!root) return 0;
        int lsum=0, rsum=0;
        lsum = max(0, sum(root->left));
        rsum = max(0, sum(root->right));

        maxi = max(maxi, lsum + rsum + root->val);
        return root->val + max(lsum,rsum);
    }

    int maxPathSum(TreeNode* root) {
        int ans = sum(root);
        return maxi;
    }
};

int main() {
    Solution solution;

    // Test case 1
    TreeNode* root1 = new TreeNode(-10);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    cout << "Maximum path sum of test case 1: " << solution.maxPathSum(root1) << endl;

    // Test case 2
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    cout << "Maximum path sum of test case 2: " << solution.maxPathSum(root2) << endl;

    // Test case 3
    TreeNode* root3 = new TreeNode(-3);
    cout << "Maximum path sum of test case 3: " << solution.maxPathSum(root3) << endl;

    // Test case 4
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(-2);
    root4->right = new TreeNode(3);
    cout << "Maximum path sum of test case 4: " << solution.maxPathSum(root4) << endl;

    return 0;
}