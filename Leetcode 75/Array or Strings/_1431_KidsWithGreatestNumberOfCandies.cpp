// There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have. Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxCandy = candies[0];
        for(int i = 1;i < candies.size();i++){
            if(candies[i] > maxCandy) maxCandy = candies[i];
        }

        for (const int candy : candies)
        ans.push_back(candy + extraCandies >= maxCandy);

        return ans;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>candies = {2,3,5,1,3};
    int extraCandies = 3;
    vector<bool>ans = solve.kidsWithCandies(candies,extraCandies);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<" ";
}