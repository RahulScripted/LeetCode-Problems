// A fancy string is a string where no three consecutive characters are equal. Given a string s, delete the minimum possible number of characters from s to make it fancy. Return the final string after the deletion. It can be shown that the answer will always be unique.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans.push_back(s[0]);
        int n = s.size(),cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i] == ans.back()){
                cnt++;
                if(cnt < 3) ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


int main(){
    Solution solve;

    // 1st Example
    string s = "leeetcode";
    cout<<"After converting "<<s<<" to fancy String "<<solve.makeFancyString(s)<<endl;

    // 2nd Example
    s = "aaabaaaa";
    cout<<"After converting "<<s<<" to fancy String "<<solve.makeFancyString(s)<<endl;
}