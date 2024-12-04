// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.




#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long i = left, j = right;
        int cnt = 0;
        while (pow(2, cnt) <= left) {
            if (i & (1 << cnt)) {
                int k = j;
                k = k | (1 << cnt);
                k ^= (1 << cnt);

                if (k >= left) i ^= (1 << cnt);
            }
            cnt++;
        }
        return i;
    }
};

int main() {
    Solution solution;
    int left, right;

    // Example 1
    left = 5;
    right = 7;
    cout << "Range Bitwise AND (" << left << ", " << right << "): " << solution.rangeBitwiseAnd(left, right) << endl;

    // Example 2
    left = 0;
    right = 1;
    cout << "Range Bitwise AND (" << left << ", " << right << "): " << solution.rangeBitwiseAnd(left, right) << endl;

    // Example 3
    left = 12;
    right = 15;
    cout << "Range Bitwise AND (" << left << ", " << right << "): " << solution.rangeBitwiseAnd(left, right) << endl;
}