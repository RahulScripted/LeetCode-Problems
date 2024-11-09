// You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x. Return the minimum possible value of nums[n - 1].





#include <iostream>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long remaining = n - 1;
        long long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    int n, x;
    cout << "Enter values for n and x: ";
    cin >> n >> x;

    long long result = solution.minEnd(n, x);
    cout << "The minimum end value is: " << result << endl;

    return 0;
}