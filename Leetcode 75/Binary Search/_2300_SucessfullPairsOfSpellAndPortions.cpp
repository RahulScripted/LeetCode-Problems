// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion. You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success. Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.






#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs;

        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            pairs.push_back(m - (lower_bound(potions.begin(), potions.end(), (double)success / spells[i]) - potions.begin()));
        }

        return pairs;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> spells = {10, 20, 30};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 100;

    // Call the function and store the result
    vector<int> result = sol.successfulPairs(spells, potions, success);

    // Output the result
    for (int r : result) cout << r << " ";
    cout << endl;
}
