// Given a triangle array, return the minimum path sum from top to bottom. For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n,0),curr(n,0);
        for(int i=0;i<n;i++){
            prev[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+prev[j];
                int dia=triangle[i][j]+prev[j+1];
                curr[j]=min(down,dia);
            }
            prev=curr;
        }
        return prev[0];
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    vector<vector<int>> triangle(n);
    cout << "Enter the elements of the triangle row by row:" << endl;
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    int result = solution.minimumTotal(triangle);
    cout << "The minimum path sum is: " << result << endl;
}