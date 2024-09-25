// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = 0;
        while(x){
            int digit = (x % 10);
            if(temp < INT_MIN / 10 || temp > INT_MAX / 10) return 0;
            temp = (temp * 10) + digit;
            x /= 10;
        }
        return temp;
    }
};

int main(){
    Solution solve;

    // 1st example
    int x = 123;
    cout<<"Reverse will be : "<<solve.reverse(x)<<endl;

    // 2nd example
    x = -123;
    cout<<"Reverse will be : "<<solve.reverse(x)<<endl;

    // 3rd example
    x = 120;
    cout<<"Reverse will be : "<<solve.reverse(x)<<endl;
}