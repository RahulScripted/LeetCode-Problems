// There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG. You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph. A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a. Team a will be the champion of the tournament if there is no team b that is stronger than team a. Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.





#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        bitset<100> losses; 
        
        for (const auto& edge : edges) losses.set(edge[1]);
        
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (!losses[i]) {
                if (champion != -1) return -1;
                champion = i;
            }
        }
        
        return champion;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (from, to):" << endl;
    for (int i = 0; i < m; ++i) cin >> edges[i][0] >> edges[i][1];

    Solution solution;
    int champion = solution.findChampion(n, edges);
    if (champion == -1) cout << "There is no unique champion." << endl;
    else cout << "The champion is node " << champion << "." << endl;
}
