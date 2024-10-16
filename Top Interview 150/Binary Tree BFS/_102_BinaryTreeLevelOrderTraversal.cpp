// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).





#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            vector<int> level;
            
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                
                level.push_back(node->val);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};

// Helper function to print the level order traversal
void printLevelOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create an instance of the solution class
    Solution solution;

    // Call the levelOrder function
    vector<vector<int>> result = solution.levelOrder(root);

    // Print the level-order traversal
    cout << "Level-order traversal of the tree: " << endl;
    printLevelOrder(result);

    return 0;
}