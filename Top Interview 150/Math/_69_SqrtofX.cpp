// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // Without built-in Function
        if (x == 0) return 0;
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == x / mid) return mid;
            else if (mid < x / mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;

        // Built-in Function
        // return sqrt(x);
    }
};

int main(){
    Solution solve;

    // 1st Example
    int x = 4;
    cout<<"Square root of "<<x<<" will be : "<<solve.mySqrt(x)<<endl;

    // 2nd Example
    x = 8;
    cout<<"Square root of "<<x<<" will be : "<<solve.mySqrt(x)<<endl;
}