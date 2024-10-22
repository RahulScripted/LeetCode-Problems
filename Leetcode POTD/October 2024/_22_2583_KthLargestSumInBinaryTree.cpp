// You are given the root of a binary tree and a positive integer k. The level sum in the tree is the sum of the values of the nodes that are on the same level. Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.





#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<long long> vec;
        long long res = 0;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int height = q.front().second;
            q.pop();

            if(vec.size() > height) vec[height] += node->val;
            else vec.push_back(node->val);

            if(node->left) q.push({node->left, height + 1});
            if(node->right) q.push({node->right, height + 1});            
        }
        
        sort(vec.rbegin(), vec.rend());
        if(k > vec.size()) return -1;
        return vec[k - 1];
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    int k = 2;
    long long result = solution.kthLargestLevelSum(root, k);

    cout << "The " << k << "th largest level sum is: " << result << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}