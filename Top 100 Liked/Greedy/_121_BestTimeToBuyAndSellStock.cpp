// You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Approach 2
        int n = prices.size() ;
        for(int i = n-1 ; i>=1 ;--i) prices[i] = prices[i]-prices[i-1];

        int sum = 0 ;
        int max_sum = 0 ;
        for(int i = 1 ;i<prices.size() ;++i){
            sum+=prices[i] ;
            max_sum = max(max_sum,sum) ;
            sum = max(sum,0) ;
        }

        return max_sum ;

        // Approach 1
        // int sellOne = 0;
        // int holdOne = INT_MIN;

        // for (const int price : prices) {
        //     sellOne = max(sellOne, holdOne + price);
        //     holdOne = max(holdOne, -price);
        // }

        // return sellOne;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>price = {7,1,5,3,6,4};
    cout<<"Maximum profit will be : "<<solve.maxProfit(price)<<endl;

    // 2nd Example
    price = {7,6,4,3,1};
    cout<<"Maximum profit will be : "<<solve.maxProfit(price)<<endl;
}