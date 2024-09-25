// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer n, return true if n is an ugly number.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return n == 1;
    }
};

int main(){
    Solution solve;

    // 1st example
    int x = 12;
    if(solve.isUgly(x)) cout<<x<<" is a ugly number"<<endl;
    else cout<<x<<" is not a ugly number"<<endl;

    // 2nd example
    x = -123;
    if(solve.isUgly(x)) cout<<x<<" is a ugly number"<<endl;
    else cout<<x<<" is not a ugly number"<<endl;

    // 3rd example
    x = 120;
    if(solve.isUgly(x)) cout<<x<<" is a ugly number"<<endl;
    else cout<<x<<" is not a ugly number"<<endl;
}