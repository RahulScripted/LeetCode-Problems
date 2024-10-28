// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai. Return true if you can finish all courses. Otherwise, return false.





#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int counter = 0;
        if (numCourses <= 0) {
            return true;
        }

        // Initialize inDegree and graph
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        // Build the graph and update inDegree for each node
        for (const auto& edge : prerequisites) {
            int parent = edge[1];
            int child = edge[0];
            graph[parent].push_back(child);
            inDegree[child]++;
        }

        // Initialize the queue with courses having no prerequisites (inDegree = 0)
        queue<int> sources;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                sources.push(i);
            }
        }

        // Process nodes with no prerequisites
        while (!sources.empty()) {
            int course = sources.front(); // dequeue
            sources.pop();
            counter++;

            // Process all the children of the current course
            for (int child : graph[course]) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    sources.push(child); // enqueue child if inDegree becomes 0
                }
            }
        }

        // If we processed all courses, return true
        return counter == numCourses;
    }
};

int main() {
    Solution solution;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    bool result = solution.canFinish(numCourses, prerequisites);

    if (result) cout << "It is possible to finish all courses." << endl;

    else cout << "It is not possible to finish all courses." << endl;
}