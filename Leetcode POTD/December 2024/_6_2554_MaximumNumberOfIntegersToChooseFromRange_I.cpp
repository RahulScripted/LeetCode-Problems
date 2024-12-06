// You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

// 1.  The chosen integers have to be in the range [1, n].

// 2.  Each integer can be chosen at most once.

// 3.  The chosen integers should not be in the array banned.

// 4.  The sum of the chosen integers should not exceed maxSum.

// Return the maximum number of integers you can choose following the mentioned rules.






#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue;
            sum += i;
            if (sum > maxSum) break;
            count++;
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<int> banned = {2, 4, 6};
    int n = 10;
    int maxSum = 20;
    int result = solution.maxCount(banned, n, maxSum);
    cout << "Maximum count of numbers that can be chosen: " << result << endl;
}