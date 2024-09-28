// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers. Given a string s, return true if it is a palindrome, or false otherwise.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end]))return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};

int main(){
    Solution solve;
    
    // 1st Example
    string s = "A man, a plan, a canal: Panama";
    if(solve.isPalindrome(s)) cout<<s<<" => is a valid palindrome"<<endl;
    else cout<<s<<" => is not a valid palindrome"<<endl;
    
    // 2nd Example
    s = "race a car";
    if(solve.isPalindrome(s)) cout<<s<<" => is a valid palindrome"<<endl;
    else cout<<s<<" => is not a valid palindrome"<<endl;
}