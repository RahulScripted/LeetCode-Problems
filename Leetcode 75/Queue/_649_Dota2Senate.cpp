// In the world of Dota2, there are two parties: the Radiant and the Dire. The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

// 1.  Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.

// 2.  Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.

// Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n. The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure. Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".






#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        int n = senate.length();

        // Add all senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') rad.push(i);
            else dir.push(i);
        }

        // Use increasing n to keep track of position
        while (!rad.empty() && !dir.empty()) {
            // Only "winner" stays in their queue
            if (rad.front() < dir.front()) rad.push(n++);
            else dir.push(n++);
            rad.pop();
            dir.pop();
        }

        return (rad.empty()) ? "Dire" : "Radiant";
    }
};

int main() {
    Solution solution;

    string senate = "RDD";
    string result = solution.predictPartyVictory(senate);

    // Print the result
    cout << "The winning party is: " << result << endl;
}