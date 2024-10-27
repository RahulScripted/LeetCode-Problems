// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable. You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?. Return the answers to all queries. If a single answer cannot be determined, return -1.0.





#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adjList;
    unordered_map<string, bool> visited;
    double queryAns;
    
    bool dfs(string startNode, string endNode, double runningProduct){
        if(adjList.find(startNode) == adjList.end() || adjList.find (endNode) == adjList.end()) return false;
        if(startNode == endNode and adjList.find(startNode)!=adjList.end()) {
            queryAns = runningProduct;
            return true;
            
        }
        
        bool tempAns = false;
        visited[startNode] = true;
        
        for(int i = 0; i < adjList[startNode].size(); i++){
            if(!visited[adjList[startNode][i].first]){
                tempAns = dfs(adjList[startNode][i].first, endNode, runningProduct*adjList[startNode][i].second);
                if(tempAns) break;
            }
        }
        
        visited[startNode] = false;
        return tempAns;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        
        for(int i = 0; i < n ; i++){
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;

        }
        
        for(int i = 0; i < m ; i++){
            queryAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);            
            if(pathFound) ans[i] = queryAns;
            else ans[i] = -1;
            
        }

        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> results = solution.calcEquation(equations, values, queries);
    for (double result : results) cout << result << " ";
    cout << endl;
}