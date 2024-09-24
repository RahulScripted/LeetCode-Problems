// Given an integer n, return true if it is a power of three. Otherwise, return false.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};

int main(){
    Solution solve;

    // 1st example
    int n = 0;
    if(solve.isPowerOfThree(n)) cout<<n<<" is power of 3"<<endl;
    else cout<<n<<" is not power of 3"<<endl;

    // 2nd example
    n = 27;
    if(solve.isPowerOfThree(n)) cout<<n<<" is power of 3"<<endl;
    else cout<<n<<" is not power of 3"<<endl;

    // 3rd example
    n = 24;
    if(solve.isPowerOfThree(n)) cout<<n<<" is power of 3"<<endl;
    else cout<<n<<" is not power of 3"<<endl;
}