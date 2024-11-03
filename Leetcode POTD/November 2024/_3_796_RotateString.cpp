// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. A shift on s consists of moving the leftmost character of s to the rightmost position.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;

        // Brute-force
        // int n=s.length();
        // int m=goal.length();
        // int i=0;
        // if(m!=n)return false;

        // while(i<n){
        //     if(s==goal) return true;
        //     char a=s[0];
        //     for(int j=0;j<n-1;j++)s[j]=s[j+1];
        //     s[n-1]=a;
        //     i++;
            
        // }
        // return false;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "abcde";
    string goal = "cdeab";

    if(solve.rotateString(s,goal)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}