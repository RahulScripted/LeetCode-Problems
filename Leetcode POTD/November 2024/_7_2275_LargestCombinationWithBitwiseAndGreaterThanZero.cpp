// You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination. Return the size of the largest combination of candidates with a bitwise AND greater than 0.

 



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size(),ans = 0;
        for(int i=0;i<32;i++){
            int cnt = 0;
            for(auto candidate : candidates){
                if(candidate & (1<<i))cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};

int main(){
    Solution solve;

    vector<int>candidates = {16,17,71,62,12,24,14};
    cout<<"The size of the largest combination will be : "<<solve.largestCombination(candidates)<<endl;
}