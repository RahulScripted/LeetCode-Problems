// Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        // Sort
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n - 1];
        int minLength = min(first.length(),last.length());

        // Adding answer
        string ans = "";
        for(int i = 0;i < minLength;i++){
            if(first[i] == last[i]) ans += first[i];
            else break;
        }
        return ans;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<string> strs = {"flower","flow","flight"};
    string ans = solve.longestCommonPrefix(strs);
    cout<<"Longest common prefix : "<<ans<<endl;

    // 2nd example
    strs = {"dog","racecar","car"};
    ans = solve.longestCommonPrefix(strs);
    cout<<"Longest common prefix : "<<ans<<endl;
}