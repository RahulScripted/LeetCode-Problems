// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k. Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        vector<int> states(k*2, INT_MIN);
        states[0] = -prices[0];

        for (auto price : prices) {
            states[0] = max(states[0], -price);
            int sign = 1;
            // for each k, we have 2 new states
            for (int i=1; i<k*2; ++i) {
                states[i] = max(states[i], states[i-1] + sign * price);
                sign *= -1;
            } 
        }

        return states[k*2-1];
    }
};

int main() {
    Solution solution;
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << "Maximum Profit: " << solution.maxProfit(k, prices) << endl;
    return 0;
}