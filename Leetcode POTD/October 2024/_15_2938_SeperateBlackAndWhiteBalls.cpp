// There are n balls on a table, each ball has a color black or white. You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively. In each step, you can choose two adjacent balls and swap them. Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.






#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') c++;
            else ans+=c;
        }
        return ans;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "101";
    cout<<"Minimum swaps required : "<<solve.minimumSteps(s)<<endl;

    // 2nd Example
    s = "01101";
    cout<<"Minimum swaps required : "<<solve.minimumSteps(s)<<endl;
}