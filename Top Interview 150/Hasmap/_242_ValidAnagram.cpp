// Given two strings s and t, return true if t is an anagram of s, and false otherwise.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Base Case
        if(s.length() != t.length()) return false;

        // Approach 3 -> Using 1 HashMap
        
        // initalize Map
        unordered_map<char,int>mp;

        // Fill
        for(int i = 0;i < s.length();i++) mp[s[i]]++;

        // Find
        for(int i = 0;i < t.length();i++){
            if(mp.find(t[i]) != mp.end()){
                if(mp[t[i]] > 0) mp[t[i]]--;
                else return false;
            }
            else return false;
        }
        return true;

        // Approach 2 -> Using 2 HashMap

        // // Initalize Map
        // unordered_map<char,int>mp1;
        // unordered_map<char,int>mp2;

        // // Fill Map
        // for(int i = 0;i < s.length();i++) mp1[s[i]]++;
        // for(int i = 0;i < t.length();i++) mp2[t[i]]++;

        // // Check
        // for(auto p : mp1){
        //     char ch1 = p.first;
        //     int freq1 = p.second;
        //     if(mp2.find(ch1) != mp2.end()){
        //         int freq2 = mp2[ch1];
        //         if(freq1 == freq2) continue;
        //         else return false;
        //     }
        //     else return false;
        // }
        // return true;

        // Approach 1 -> By Sorting
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s == t;
    }
};

int main(){
    Solution solve;

    // 1st Example
    string s = "anagram";
    string t = "nagaram";

    if(solve.isAnagram(s,t)) cout<<"Valid anagram"<<endl;
    else cout<<"Not valid anagram"<<endl;

    // 2nd Example
    s = "rat";
    t = "car";

    if(solve.isAnagram(s,t)) cout<<"Valid anagram"<<endl;
    else cout<<"Not valid anagram"<<endl;

    // 3rd Example
    s = "aacesd";
    t = "dseaac";

    if(solve.isAnagram(s,t)) cout<<"Valid anagram"<<endl;
    else cout<<"Not valid anagram"<<endl;
}