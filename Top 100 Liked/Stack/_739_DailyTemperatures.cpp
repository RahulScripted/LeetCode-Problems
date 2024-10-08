// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Without Stack
        int n = temperatures.size();
        vector<int> largest(n);
        largest.back() = -1;
        
        for(int i = n - 2; i >= 0; i--) {
            if(temperatures[i] < temperatures[i + 1]) largest[i] = i + 1;
            else {
                int j = i + 1;
                while(j != -1 && temperatures[i] >= temperatures[j]) j = largest[j];
                largest[i] = j;
            }
        }

        for(int i = 0; i < largest.size(); i++) {
            if(largest[i] == -1) largest[i] = 0;
            else largest[i] = largest[i] - i;
        }
        return largest;

        // With Stack
        // int n = temperatures.size();
        // vector<int> ans(n);
        // stack<int> stack;  

        // for (int i = 0; i < n; ++i) {
        //     while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
        //         const int index = stack.top();
        //         stack.pop();
        //         ans[index] = i - index;
        //     }
        //     stack.push(i);
        // }

        // return ans;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>temperatures = {73,74,75,71,69,72,76,73};
    vector<int>res = solve.dailyTemperatures(temperatures);
    cout<<"Warmer temperature list : ";
    for(int i = 0;i < res.size();i++) cout<<res[i]<<" ";
}