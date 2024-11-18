// You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k. To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

// 1.  If k > 0, replace the ith number with the sum of the next k numbers.

// 2.  If k < 0, replace the ith number with the sum of the previous k numbers.

// 3.  If k == 0, replace the ith number with 0.


// As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1]. Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!





#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        if (k > 0) {
            int wsum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            ans[0] = wsum;
            for (int l = 1, r = k + 1; l < n; r++, l++) {
                wsum += -code[l] + code[r % n];
                ans[l] = wsum;
            }
            return ans;
        }
        // k < 0
        k = -k;
        int wsum = accumulate(code.end() - k, code.end(), 0);
        ans[0] = wsum;
        for (int r = 0, l = n - k; r < n - 1; r++, l++) {
            wsum += -code[l % n] + code[r];
            ans[r + 1] = wsum;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> code1 = {5, 7, 1, 4};
    int k1 = 3;
    vector<int> result1 = solution.decrypt(code1, k1);
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> code2 = {1, 2, 3, 4};
    int k2 = 0;
    vector<int> result2 = solution.decrypt(code2, k2);
    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> code3 = {2, 4, 9, 3};
    int k3 = -2;
    vector<int> result3 = solution.decrypt(code3, k3);
    cout << "Result 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}