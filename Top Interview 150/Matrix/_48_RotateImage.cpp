// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Approach 2
        int row = matrix.size();
        // Transpose
        for(int i = 0;i < row;i++){
            for(int j = (i + 1);j < row;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // Reverse
        for(int k = 0;k < row;k++){
            int i = 0,j = (row - 1);
            while(i <= j){
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
                i++;
                j--;
            }
        }

        // Approach 1
        // for (int mn = 0; mn < matrix.size() / 2; ++mn) {
        //     const int mx = matrix.size() - mn - 1;
        //     for (int i = mn; i < mx; ++i) {
        //         const int offset = i - mn;
        //         const int top = matrix[mn][i];
        //         matrix[mn][i] = matrix[mx - offset][mn];
        //         matrix[mx - offset][mn] = matrix[mx][mx - offset];
        //         matrix[mx][mx - offset] = matrix[i][mx];
        //         matrix[i][mx] = top;
        //     }
        // }

        // Brute-force
        // reverse(matrix.begin(),matrix.end());
        // for (int i = 0; i < matrix.size(); ++i){
        //     for (int j = i + 1; j < matrix.size(); ++j) swap(matrix[i][j], matrix[j][i]);
        // }
    }
};

void display(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st Example
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Before rotation : "<<endl;
    display(matrix);
    solve.rotate(matrix);
    cout<<"After rotation : "<<endl;
    display(matrix);
}