// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.





#include <iostream>
#include <climits>
#include <stack>
using namespace std;

// TreeNode definition (from the problem statement)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* node){
        for( ; node != NULL ; st.push(node), node=node->left);
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        BSTIterator l(root);

        int curr,nxt;
        if(l.hasNext()) curr = l.next();
        
        while(l.hasNext()){
            if(l.hasNext()) nxt = l.next();
            ans = min(ans,abs(curr-nxt));
            curr = nxt;
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    int result = solution.getMinimumDifference(root);
    cout << "The minimum absolute difference in the BST is: " << result << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}