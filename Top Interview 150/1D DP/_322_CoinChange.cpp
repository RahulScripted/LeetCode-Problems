// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.





#include <iostream>
#include <vector>
#include <algorithm>  // For std::min
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Permutation
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (const int coin : coins) {
                if (coin <= i) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];

        // Combination
        // vector<int> dp(amount + 1, amount + 1);
        // dp[0] = 0;

        // for (const int coin : coins){
        //     for (int i = coin; i <= amount; ++i) dp[i] = min(dp[i], dp[i - coin] + 1);
        // }

        // return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Fewest number of coins to make " << amount1 << ": " << solution.coinChange(coins1, amount1) << endl;

    // Test case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Fewest number of coins to make " << amount2 << ": " << solution.coinChange(coins2, amount2) << endl;

    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Fewest number of coins to make " << amount3 << ": " << solution.coinChange(coins3, amount3) << endl;

    return 0;
}