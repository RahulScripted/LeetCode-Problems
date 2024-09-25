// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        return str1.substr(0,__gcd(str1.length(),str2.length()));
    }
};

int main(){
    Solution solve;

    // 1st example
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout<<"First string : "<<str1<<endl;
    cout<<"Second string : "<<str2<<endl;
    cout<<"Common string : "<<solve.gcdOfStrings(str1,str2)<<endl;

    cout<<endl;

    // 2nd example
    str1 = "ABABAB";
    str2 = "AB";
    cout<<"First string : "<<str1<<endl;
    cout<<"Second string : "<<str2<<endl;
    cout<<"Common string : "<<solve.gcdOfStrings(str1,str2)<<endl;

    cout<<endl;

    // 3rd example
    str1 = "LEET";
    str2 = "CODE";
    cout<<"First string : "<<str1<<endl;
    cout<<"Second string : "<<str2<<endl;
    cout<<"Common string : "<<solve.gcdOfStrings(str1,str2)<<endl;
}