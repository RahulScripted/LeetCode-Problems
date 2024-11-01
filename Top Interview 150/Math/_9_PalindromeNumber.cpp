// Given an integer x, return true if x is a palindrome, and false otherwise.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Base condition
        if(x < 0) return false;
        // Reverse it
        int temp = x,reverse = 0;
        while(temp){
            int digit = (temp % 10);
            if(reverse < INT_MIN / 10 || reverse > INT_MAX / 10) return false;
            reverse = (reverse * 10) + digit;
            temp /= 10;
        }
        return x == reverse;
    }
};

int main(){
    Solution solve;

    // 1st Example
    int x = 121;
    if(solve.isPalindrome(x)) cout<<x<<" is a palindrome number"<<endl;
    else cout<<x<<" is not a palindrome number"<<endl;
}