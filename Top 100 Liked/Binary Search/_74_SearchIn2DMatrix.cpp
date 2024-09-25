// You are given an m x n integer matrix matrix with the following two properties:

// 1.   Each row is sorted in non-decreasing order.
// 2.   The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search
        int row = matrix.size();
        int col = matrix[0].size();
        int lo = 0,hi = (row * col);
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            const int i = mid / col;
            const int j = mid % col;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) lo = mid + 1;
            else hi = mid;
        }
        return false;
        
        // Linear search (Method 1)
        // int row = matrix.size();
        // int col = matrix[0].size();
        // for(int i = 0;i < row;i++){
        //     for(int j = 0;j < col;j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    if(solve.searchMatrix(matrix,target)) cout<<target<<" founded"<<endl;
    else cout<<target<<" is not founded"<<endl;

    // 2nd example
    matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    target = 13;
    if(solve.searchMatrix(matrix,target)) cout<<target<<" founded"<<endl;
    else cout<<target<<" is not founded"<<endl;
}