// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation). Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // Inbuilt Function
        return __builtin_popcount((c & a) ^ a) + __builtin_popcount((c & b) ^ b) + __builtin_popcount(((a | b) & c) ^ c);
    }
};

int main(){
    Solution solve;

    // 1st Example
    int a = 2,b = 6,c = 5;
    cout<<"Minimum flips required : "<<solve.minFlips(a,b,c)<<endl;

    // 2nd Example
    a = 4,b = 2,c = 7;
    cout<<"Minimum flips required : "<<solve.minFlips(a,b,c)<<endl;
}