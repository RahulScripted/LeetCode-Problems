// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                res += 1;
            }
        }
        return res;    
    }
};

int main(){
    Solution solve;

    int n = 11;
    cout<<"No. of set bits are : "<<solve.hammingWeight(n)<<endl;
}