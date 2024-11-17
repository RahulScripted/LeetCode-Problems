// Given an integer n, return the number of trailing zeroes in n!.




#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for (long long i = 5; n / i > 0; i *= 5) {
            result += (n / i);
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Input the number
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = solution.trailingZeroes(n);
    cout << "The number of trailing zeroes in " << n << "! is: " << result << endl;

    return 0;
}