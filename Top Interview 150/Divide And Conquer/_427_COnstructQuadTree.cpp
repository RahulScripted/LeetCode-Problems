// Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

// Return the root of the Quad-Tree representing grid.

// A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

// val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
// isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
// class Node {
//     public boolean val;
//     public boolean isLeaf;
//     public Node topLeft;
//     public Node topRight;
//     public Node bottomLeft;
//     public Node bottomRight;
// }
// We can construct a Quad-Tree from a two-dimensional area using the following steps:

// If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
// If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
// Recurse for each of the children with the proper sub-grid.

// If you want to know more about the Quad-Tree, you can refer to the wiki.

// Quad-Tree format:

// You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

// It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

// If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.





#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// Solution class containing the QuadTree construction methods
class Solution {
public:
    // Helper function to check if all values in a subgrid are the same
    bool sameVal(vector<vector<int>>& grid, int x, int y, int size) {
        for (auto i = x; i < x + size; ++i) {
            for (auto j = y; j < y + size; ++j) {
                if (grid[i][j] != grid[x][y]) return false;
            }
        }
        return true;
    }

    // Recursive function to build the QuadTree
    void rec(Node* root, vector<vector<int>>& grid, int x, int y, int size) {
        if (sameVal(grid, x, y, size)) {
            root->val = grid[x][y];
            root->isLeaf = true;
            return;
        }

        const auto new_size = size / 2;

        root->topLeft = new Node();
        rec(root->topLeft, grid, x, y, new_size);

        root->topRight = new Node();
        rec(root->topRight, grid, x, y + new_size, new_size);

        root->bottomLeft = new Node();
        rec(root->bottomLeft, grid, x + new_size, y, new_size);

        root->bottomRight = new Node();
        rec(root->bottomRight, grid, x + new_size, y + new_size, new_size);
    }

    // Main function to construct the QuadTree
    Node* construct(vector<vector<int>>& grid) {
        const auto n = grid.size();
        auto root = new Node();
        rec(root, grid, 0, 0, n);
        return root;
    }
};

// Function to print the QuadTree (for debugging and visualization)
void printQuadTree(Node* root, int depth = 0) {
    if (!root) return;
    for (int i = 0; i < depth; ++i) cout << "  ";
    if (root->isLeaf) {
        cout << "Leaf(val=" << root->val << ")" << endl;
    } else {
        cout << "Node" << endl;
        printQuadTree(root->topLeft, depth + 1);
        printQuadTree(root->topRight, depth + 1);
        printQuadTree(root->bottomLeft, depth + 1);
        printQuadTree(root->bottomRight, depth + 1);
    }
}

// Main function to test the solution
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    Solution solution;
    Node* root = solution.construct(grid);

    cout << "QuadTree structure:" << endl;
    printQuadTree(root);

    return 0;
}