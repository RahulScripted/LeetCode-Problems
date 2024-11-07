// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x: nums) m[x]++;
        
        for(auto x: m){
            if(x.second == 1) return x.first;
        }
        
        return -1;
    }
};

int main(){
    Solution solve;

    vector<int>nums = {2,2,3,2};
    cout<<"Single number is : "<<solve.singleNumber(nums)<<endl;
}