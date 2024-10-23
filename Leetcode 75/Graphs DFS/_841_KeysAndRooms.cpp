// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key. When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms. Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool> &cont) {
        cont[i] = true;
        for(auto j : rooms[i]) {
            if(!cont[j]) dfs(j, rooms, cont); 
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> cont(n, false);
        cont[0] = true;
        dfs(0, rooms, cont);
        for(auto j : cont) {
            if(!j) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};  
    vector<vector<int>> rooms2 = {{1,3}, {3,0,1}, {2}, {0}}; 

    Solution sol;

    // Test case 1
    cout << "Test case 1: " << (sol.canVisitAllRooms(rooms1) ? "All rooms can be visited." : "Not all rooms can be visited.") << endl;

    // Test case 2
    cout << "Test case 2: " << (sol.canVisitAllRooms(rooms2) ? "All rooms can be visited." : "Not all rooms can be visited.") << endl;

    return 0;
}