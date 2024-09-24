// Given an integer n, return true if it is a power of two. Otherwise, return false.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main(){
    Solution solve;

    // 1st example
    int n = 0;
    if(solve.isPowerOfTwo(n)) cout<<n<<" is power of 2"<<endl;
    else cout<<n<<" is not power of 2"<<endl;

    // 2nd example
    n = 16;
    if(solve.isPowerOfTwo(n)) cout<<n<<" is power of 2"<<endl;
    else cout<<n<<" is not power of 2"<<endl;

    // 3rd example
    n = 24;
    if(solve.isPowerOfTwo(n)) cout<<n<<" is power of 2"<<endl;
    else cout<<n<<" is not power of 2"<<endl;
}