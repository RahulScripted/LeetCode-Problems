// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).




#include <iostream>
using namespace std;

class Solution {
public:
    double binaryExp(double x, long n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / binaryExp(x, -n);
       
        if (n % 2 == 1) return x * binaryExp(x * x, (n - 1) / 2);
        else return binaryExp(x * x, n / 2);
    }

    double myPow(double x, int n) {
        return binaryExp(x, static_cast<long>(n));
    }
};

int main() {
    Solution solution;

    double x = 2.0;
    int n = 10;   
    
    double result = solution.myPow(x, n);
    cout << "Result: " << result << endl;

    x = 2.1, n = 3;
    cout << "Result for " << x << "^" << n << ": " << solution.myPow(x, n) << endl;

    x = 2.0, n = -2;
    cout << "Result for " << x << "^" << n << ": " << solution.myPow(x, n) << endl;
}