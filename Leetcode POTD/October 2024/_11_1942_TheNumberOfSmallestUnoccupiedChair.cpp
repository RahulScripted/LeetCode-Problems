// There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number. When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair. You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leaving [i], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct. Return the chair number that the friend numbered targetFriend will sit on.





#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int nextChair = 0;
        int targetStart = times[targetFriend][0];
        
        // Sort times based on arrival time
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leave_chair;
        priority_queue<int, vector<int>, greater<int>> available_chairs;

        // Iterate over the sorted times
        for (auto& time : times) {
            int start = time[0], leave = time[1];

            while (!leave_chair.empty() && leave_chair.top().first <= start) {
                available_chairs.push(leave_chair.top().second);
                leave_chair.pop();
            }

            int sat;
            if (!available_chairs.empty()) {
                sat = available_chairs.top();
                available_chairs.pop();
            } 
            else sat = nextChair++;

            leave_chair.push({leave, sat});
            if (start == targetStart) return sat;
        }

        return -1;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> times1 = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend1 = 0;
    cout << "Smallest chair for friend " << targetFriend1 << ": " << solution.smallestChair(times1, targetFriend1) << endl;

    // Test case 2
    vector<vector<int>> times2 = {{3, 10}, {1, 5}, {2, 6}};
    int targetFriend2 = 1;
    cout << "Smallest chair for friend " << targetFriend2 << ": " << solution.smallestChair(times2, targetFriend2) << endl;

    // Test case 3
    vector<vector<int>> times3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int targetFriend3 = 3;
    cout << "Smallest chair for friend " << targetFriend3 << ": " << solution.smallestChair(times3, targetFriend3) << endl;

    return 0;
}