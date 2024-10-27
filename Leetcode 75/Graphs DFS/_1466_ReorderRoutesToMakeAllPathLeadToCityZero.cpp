// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow. Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi. This year, there will be a big event in the capital (city 0), and many people want to travel to this city. Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.





#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {
                count += sign;
                dfs(neighbor, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(0, -1, adj);
        return count;
    }
};

int main() {
    Solution solution;
    
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}
    };
    
    int result = solution.minReorder(n, connections);
    cout << "Minimum reorders required: " << result << endl;
}