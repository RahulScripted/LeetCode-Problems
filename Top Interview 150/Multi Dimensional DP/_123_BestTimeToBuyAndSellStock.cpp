// You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. You may complete at most two transactions.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdOne = INT_MIN;
        int sellOne = 0;
        int holdTwo = INT_MIN;
        int sellTwo = 0;

        for(int price:prices){
            holdOne = max(holdOne,-price);
            sellOne = max(sellOne,price + holdOne);
            holdTwo = max(holdTwo,-price + sellOne);
            sellTwo = max(sellTwo,price + holdTwo);
        }
        return sellTwo;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Maximum Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}
