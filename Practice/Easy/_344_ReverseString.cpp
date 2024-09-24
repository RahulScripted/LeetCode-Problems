// Write a function that reverses a string. The input string is given as an array of characters s.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int lo = 0,hi = (n - 1);
        while(lo < hi) swap(s[lo++],s[hi--]);
    }
};

void display(vector<char>& s){
    int n = s.size();
    for(int i = 0;i < n;i++) cout<<s[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st example
    vector<char> s = {'h','e','l','l','o'};
    cout<<"Before reversing : ";
    display(s);
    cout<<"After reversing : ";
    solve.reverseString(s);
    display(s);

    cout<<endl;

    // 2nd example
    s = {'w','o','r','l','d','s'};
    cout<<"Before reversing : ";
    display(s);
    cout<<"After reversing : ";
    solve.reverseString(s);
    display(s);
}