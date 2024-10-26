// You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m. You have to perform m independent queries on the tree where in the ith query you do the following: Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root. Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.





#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int N = 100001;

class Solution {
public:
    int val2H[N], removal[N];
    int h(TreeNode* root) {
        if (!root) return -1;
        int x = root->val;
        if (val2H[x] != -1) return val2H[x];
        return val2H[x] = 1 + max(h(root->left), h(root->right));
    }

    void dfs(TreeNode* root, int level, int maxLevel) {
        if (!root) return;
        int x = root->val;
        removal[x] = maxLevel;
        dfs(root->left, level + 1, max(maxLevel, 1 + level + h(root->right)));
        dfs(root->right, level + 1, max(maxLevel, 1 + level + h(root->left)));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        memset(val2H, -1, sizeof(val2H));
        memset(removal, -1, sizeof(removal));
        dfs(root, 0, 0);

        vector<int> ans(queries.size());
        int i = 0;
        for (int q : queries) ans[i++] = removal[q];
        return ans;
    }
};

// Build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    vector<int> treeNodes = {1, 2, 3, -1, 4, 5, 6}; 
    TreeNode* root = buildTree(treeNodes);
    
    vector<int> queries = {2, 3, 4, 5};
    Solution sol;
    vector<int> result = sol.treeQueries(root, queries);

    // Output results
    cout << "Results of queries:" << endl;
    for (int res : result) cout << res << " ";
    cout << endl;
}