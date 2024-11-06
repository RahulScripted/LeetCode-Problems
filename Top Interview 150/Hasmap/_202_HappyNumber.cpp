// Write an algorithm to determine if a number n is happy. A happy number is a number defined by the following process:

// 1.  Starting with any positive integer, replace the number by the sum of the squares of its digits.

// 2.  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.

// 3.  Those numbers for which this process ends in 1 are happy.

// Return true if n is a happy number, and false if not.





#include <iostream>
using namespace std;

class Solution {
public:
    int getNextNumber(int n) {
        int output = 0;
        
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }
        
        return output;
    }

    bool isHappy(int n) {
        int slow = getNextNumber(n);
        int fast = getNextNumber(slow);

        while (slow != fast) {
            if (fast == 1) return true;
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        }

        return slow == 1;
    }
};

int main() {
    Solution solution;

    // Test case 1
    int n1 = 19;
    bool result1 = solution.isHappy(n1);
    cout << "Is " << n1 << " a happy number? " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    int n2 = 2;
    bool result2 = solution.isHappy(n2);
    cout << "Is " << n2 << " a happy number? " << (result2 ? "Yes" : "No") << endl;

    // Test case 3
    int n3 = 7;
    bool result3 = solution.isHappy(n3);
    cout << "Is " << n3 << " a happy number? " << (result3 ? "Yes" : "No") << endl;

    return 0;
}