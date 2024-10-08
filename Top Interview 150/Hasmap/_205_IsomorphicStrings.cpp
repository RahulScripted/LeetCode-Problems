// Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> charToIndex_s(128);
        vector<int> charToIndex_t(128);

        for (int i = 0; i < s.length(); ++i) {
            if (charToIndex_s[s[i]] != charToIndex_t[t[i]]) return false;
            charToIndex_s[s[i]] = i + 1;
            charToIndex_t[t[i]] = i + 1;
        }

        return true;

        // Using Map
        // if(s.size()!=t.size()) return false;

        // unordered_map<char,char>m1;
        // unordered_map<char,bool>m2;
        
        // for(int i=0; i<s.size(); i++){
        //     char ans=s[i];
        //     char ans1=t[i];
        //     if(m1.find(ans)!=m1.end()){
        //         auto it=m1.find(ans);
        //         if(it->second!=ans1) return false;
        //     }
        //     else{
        //         if(m2.find(ans1)!=m2.end()) return false;
        //         else{
        //             m1.insert({ans,ans1});
        //             m2.insert({ans1,true});
        //         }
        //     }
        // }
        // return true;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "egg"; 
    string t = "add"; 
    if(solve.isIsomorphic(s,t)) cout<<s<<" and "<<t<<" are isomorphic strings"<<endl;
    else  cout<<s<<" and "<<t<<" are not isomorphic strings"<<endl;

    // 2nd Example
    s = "foo"; 
    t = "bar"; 
    if(solve.isIsomorphic(s,t)) cout<<s<<" and "<<t<<" are isomorphic strings"<<endl;
    else  cout<<s<<" and "<<t<<" are not isomorphic strings"<<endl;
}