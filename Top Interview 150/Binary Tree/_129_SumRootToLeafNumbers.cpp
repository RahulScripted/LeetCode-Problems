// You are given the root of a binary tree containing digits from 0 to 9 only. Each root-to-leaf path in the tree represents a number. Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer. A leaf node is a node with no children.





#include <iostream>
#include <string>
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
    int find(TreeNode* root, string a) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return stoi(a + to_string(root->val));
        return find(root->left, a + to_string(root->val)) + find(root->right, a + to_string(root->val));
    }

    int sumNumbers(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return root->val;
        string a = "";
        return find(root, a);
    }
};

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int sum = solution.sumNumbers(root);

    cout << "Sum of all root-to-leaf numbers: " << sum << endl;

    return 0;
}