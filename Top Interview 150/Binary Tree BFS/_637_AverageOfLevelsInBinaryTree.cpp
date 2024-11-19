// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.





#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
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
    vector<pair<double, int>> ans;
    void dfs(int level, TreeNode* root) {
        if (!root) return;
        if (ans.size() < level) ans.push_back({root->val, 1});
        else {
            ans[level - 1].first += root->val;
            ans[level - 1].second += 1;
        }
        dfs(level + 1, root->left);
        dfs(level + 1, root->right);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        dfs(1, root);
        for (int i = 0; i < ans.size(); i++) res.push_back(ans[i].first / ans[i].second);
        return res;
    }
};

int main() {
    // Constructing a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<double> result = sol.averageOfLevels(root);

    // Printing the result
    cout << "Average of levels: ";
    for (double avg : result) cout << avg << " ";
    cout << endl;

    // Cleaning up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
}