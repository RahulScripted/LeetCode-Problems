// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on. Return the smallest level x such that the sum of all the values of nodes at level x is maximal.





#include <iostream>
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
    int maxLevelSum(TreeNode* root) {
        int res;
        int ans=-1e9;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int siz= q.size();
            level++;
            long currsum=0;
            for(int i=0; i<siz; i++){
                TreeNode* temp= q.front();
                q.pop();
                currsum+= temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(currsum>ans){
                res=level;
                ans= currsum;     
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);


    int result = solution.maxLevelSum(root);
    cout << "The level with the maximum sum is: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}