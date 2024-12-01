// Given an array arr of integers, check if there exist two indices i and j such that :

// 1.  i != j

// 2.  0 <= i, j < arr.length

// 3.  arr[i] == 2 * arr[j]





#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) return true;
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> testCases = {
        {10, 2, 5, 3},
        {7, 1, 14, 11},
        {3, 1, 7, 11},
        {-2, 0, 10, -19, 4, 6, -8}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << ": ";
        bool result = solution.checkIfExist(testCases[i]);
        cout << (result ? "True" : "False") << endl;
    }
}