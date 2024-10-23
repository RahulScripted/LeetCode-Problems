// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values. Two nodes of a binary tree are cousins if they have the same depth with different parents. Return the root of the modified tree.





#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    void dfs(vector<TreeNode*> arr) {
        if (arr.empty()) return;

        int sum = 0;
        for (auto node : arr) {
            if (!node) continue;
            if (node->left) sum += node->left->val;
            if (node->right) sum += node->right->val;
        }

        vector<TreeNode*> childArr;
        for (auto node : arr) {
            int curSum = 0;
            if (node->left) curSum += node->left->val;
            if (node->right) curSum += node->right->val;

            if (node->left) {
                node->left->val = sum - curSum;
                childArr.push_back(node->left);
            }
            if (node->right) {
                node->right->val = sum - curSum;
                childArr.push_back(node->right);
            }
        }

        dfs(childArr);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        dfs(vector<TreeNode*>{root});
        return root;
    }
};

// Helper function to print the tree in level order (for visualization)
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> level{root};
    while (!level.empty()) {
        vector<TreeNode*> nextLevel;
        for (TreeNode* node : level) {
            if (node) {
                cout << node->val << " ";
                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
        }
        cout << endl;
        level = nextLevel;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Print the original tree
    cout << "Original tree (Level order):" << endl;
    printLevelOrder(root);

    // Call the function
    Solution sol;
    TreeNode* newRoot = sol.replaceValueInTree(root);

    // Print the modified tree
    cout << "Tree after replacing values (Level order):" << endl;
    printLevelOrder(newRoot);

    return 0;
}