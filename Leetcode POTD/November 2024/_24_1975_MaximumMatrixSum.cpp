// You are given an n x n integer matrix. You can do the following operation any number of times:

// 1.  Choose any two adjacent elements of matrix and multiply each of them by -1.

// 2.  Two elements are considered adjacent if and only if they share a border.

// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.





#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minAbs=INT_MAX, cntNeg=0;
        for(auto& row: matrix){
            for(int x: row){
                minAbs=min(minAbs, abs(x));
                if (x<0){
                    sum-=x;
                    cntNeg++;
                }
                else sum+=x;
            }
        }
        return (cntNeg&1)?sum-2*minAbs:sum;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    long long result = solution.maxMatrixSum(matrix);
    cout << "The maximum matrix sum is: " << result << endl;
}