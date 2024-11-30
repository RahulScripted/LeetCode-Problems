// You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti. Return any valid arrangement of pairs.





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;// net outdegree
    inline void build_graph(vector<vector<int>>& pairs){
        for(auto& edge: pairs){
            int start=edge[0], end=edge[1];
            adj[start].push_back(end);
            deg[start]++;
            deg[end]--;
        }
    }

    vector<int> rpath;
    inline void euler(int i){
        vector<int> stk={i};
        while(!stk.empty()){
            i = stk.back();
            if(adj[i].empty()){
                rpath.push_back(i);
                stk.pop_back();
            } 
            else {
                int j=adj[i].back();
                adj[i].pop_back();
                stk.push_back(j);
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        const int e = pairs.size();
        adj.reserve(e);
        deg.reserve(e);
    
        build_graph(pairs);

        int i0=deg.begin()->first;
        //Find start vertex for Euler path 
        for (auto& [v, d]: deg){
            if (d == 1){
                i0=v;
                break;
            } 
        }

        euler(i0);

        vector<vector<int>> ans;
        ans.reserve(e);

        for (int i=rpath.size()-2; i>=0; i--) 
            ans.push_back({rpath[i+1], rpath[i]});

        return ans;
    }
};

int main() {
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 1}
    };

    Solution solution;
    vector<vector<int>> result = solution.validArrangement(pairs);

    cout << "Valid arrangement of edges (Eulerian path):" << endl;
    for (const auto& edge : result) {
        cout << edge[0] << " -> " << edge[1] << endl;
    }

    return 0;
}