// Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of the graph.





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    bool isPresent(vector<Node*> nodes, Node* node) {
        for (Node* nodeItr : nodes) {
            if (nodeItr->val == node->val) return true;
        }
        return false;
    }

    void fillDfs(Node* cloneNode, Node* node, unordered_map<int, Node*>& clonedNodesPool) {
        for (Node* child : node->neighbors) {
            if (!isPresent(cloneNode->neighbors, child)) {
                if (clonedNodesPool.find(child->val) == clonedNodesPool.end()) {
                    Node* cloneChild = new Node(child->val);
                    clonedNodesPool[cloneChild->val] = cloneChild;
                    cloneNode->neighbors.push_back(cloneChild);
                    fillDfs(cloneChild, child, clonedNodesPool);
                } else {
                    Node* cloneChild = clonedNodesPool[child->val];
                    cloneNode->neighbors.push_back(cloneChild);
                }
            }
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        unordered_map<int, Node*> clonedNodesPool;
        Node* clonedHead = new Node(node->val);
        clonedNodesPool[clonedHead->val] = clonedHead;
        fillDfs(clonedHead, node, clonedNodesPool);
        return clonedHead;
    }
};

// Function to print the graph (for testing purposes)
void printGraph(Node* node, unordered_map<int, bool>& visited) {
    if (!node || visited[node->val]) return;

    visited[node->val] = true;
    cout << "Node " << node->val << " has neighbors: ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Create a sample graph manually
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution solution;

    // Clone the graph
    Node* clonedGraph = solution.cloneGraph(node1);

    // Print the original graph
    cout << "Original Graph:" << endl;
    unordered_map<int, bool> visitedOriginal;
    printGraph(node1, visitedOriginal);

    // Print the cloned graph
    cout << "\nCloned Graph:" << endl;
    unordered_map<int, bool> visitedCloned;
    printGraph(clonedGraph, visitedCloned);
}