// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai. Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isCyclic(int i, int numCourses, vector<int> adj[], vector<bool>& vis, vector<bool>& tempvis, vector<int>& ans) {
        vis[i] = true;
        tempvis[i] = true;

        for (int u : adj[i]) {
            if (tempvis[u])
                return true;
            else if (!vis[u])
                if (isCyclic(u, numCourses, adj, vis, tempvis, ans))
                    return true;
        }

        tempvis[i] = false;
        ans.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> ans;
        vector<bool> vis(numCourses, false);
        vector<bool> tempvis(numCourses, false);
        bool final_ans = true;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i])
                if (isCyclic(i, numCourses, adj, vis, tempvis, ans)) {
                    final_ans = false;
                    break;
                }
        }

        reverse(ans.begin(), ans.end());
        if (final_ans) return ans;
        ans.clear();
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> result = solution.findOrder(numCourses, prerequisites);

    if (!result.empty()) {
        cout << "Order of courses to finish all courses: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    } 
    else {
        cout << "It is impossible to finish all courses." << endl;
    }

    return 0;
}