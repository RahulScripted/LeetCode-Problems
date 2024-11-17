// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;     
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits:\n";
    for (int i = 0; i < n; i++) cin >> digits[i];
    vector<int> result = solution.plusOne(digits);

    // Output the result
    cout << "Result after adding one:\n";
    for (int digit : result) cout << digit;
    cout << endl;
}