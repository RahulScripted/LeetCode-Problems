// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee. Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.





#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;

    int h(vector<int>& p, int i, int can_buy, int fee) {
        if (i >= p.size())
            return 0;
        if (dp[i][can_buy] != -1)
            return dp[i][can_buy];
        
        int profit = h(p, i + 1, can_buy, fee);
        if (can_buy)
            profit = max(profit, -p[i] + h(p, i + 1, 0, fee));
        else
            profit = max(profit, p[i] + h(p, i + 1, 1, fee) - fee);

        return dp[i][can_buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 1)
            return 0;
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return h(prices, 0, 1, fee);
    }
};

int main() {
    Solution sol;

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = sol.maxProfit(prices, fee);
    cout << "Maximum profit with transaction fee of " << fee << ": " << result << endl;
}