// You are given an integer n and a 2D integer array queries. There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1. queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1. Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.





#include <iostream>
#include <vector>
#include <numeric> // for iota
#include <queue>   // for queue
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> dist(n);

        iota(dist.begin(), dist.end(), 0); //fills the array with 0,1,2,3...
        for (int i = 0; i < n - 1; i++) adj[i].push_back(i + 1);
        
        for (auto it : queries) {
            int src = it[0], des = it[1];
            adj[src].push_back(des);

            if (dist[src] + 1 < dist[des]) {
                queue<int> q;
                q.push(des);
                dist[des] = dist[src] + 1;

                while (q.size()) {
                    int idx = q.front();
                    q.pop();

                    for (auto e : adj[idx]) {
                        if (dist[idx] + 1 < dist[e]) {
                            dist[e] = dist[idx] + 1;
                            q.push(e);
                        }

                    }
                }
            }

            ans.emplace_back(dist.back());
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5;
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 4}, {0, 3}, {3, 4}};

    vector<int> result = solution.shortestDistanceAfterQueries(n, queries);
    cout << "Shortest distances after queries: ";
    for (int distance : result) cout << distance << " ";
    cout << endl;
}