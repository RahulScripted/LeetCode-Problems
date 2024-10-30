// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes. Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.




#include <iostream>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        long long ans = 1, mod = 1e9 + 7, a = 0, b = 1, c = 1;
        for (int i = 2; i <= n; i++) {
            ans = c * 2 + a;
            a = b;
            b = c;
            c = ans % mod;
        }
        return ans % mod;
    }
};

int main() {
    Solution sol;

    int n = 5;
    int result = sol.numTilings(n);
    cout << "Number of ways to tile a 2x" << n << " board: " << result << endl;

    return 0;
}