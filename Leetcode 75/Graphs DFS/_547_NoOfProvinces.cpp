// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c. A province is a group of directly or indirectly connected cities and no other cities outside of the group. You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise. Return the total number of provinces.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int vtx, vector<int> adj[], vector<int>& visited) {
        visited[vtx] = 1;
        for (auto it : adj[vtx]) {
            if (!visited[it]) dfs(it, adj, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited(v, 0);
        int no_provinces = 0;

        vector<int> adj[v];
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                no_provinces++;
            }
        }

        return no_provinces;
    }
};

int main() {
    vector<vector<int>> isConnected1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    Solution sol;

    // Test case 1
    cout << "Test case 1: Number of provinces = " << sol.findCircleNum(isConnected1) << endl;

    // Test case 2
    cout << "Test case 2: Number of provinces = " << sol.findCircleNum(isConnected2) << endl;

    return 0;
}