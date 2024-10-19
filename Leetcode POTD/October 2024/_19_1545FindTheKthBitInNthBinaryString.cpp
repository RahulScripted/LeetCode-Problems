// Given two positive integers n and k, the binary string Sn is formed as follows:

// 1.  S1 = "0"

// 2.  Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1

// Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0). Return the kth bit in Sn. It is guaranteed that k is valid for the given n.






#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;
        
        if (k == mid) return '1';
        else if (k < mid) return findKthBit(n - 1, k);
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};

int main() {
    Solution sol;
    int n, k;
    
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    
    char result = sol.findKthBit(n, k);
    cout << "The " << k << "-th bit in the binary string for n = " << n << " is: " << result << endl;
    
    return 0;
}