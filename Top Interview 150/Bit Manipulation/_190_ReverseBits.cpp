// Reverse bits of a given 32 bits unsigned integer.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

int main(){
    Solution solve;

    uint32_t n = 0b00000010100101000001111010011100;
    cout<<"After reversing it will be : "<<solve.reverseBits(n)<<endl;
}