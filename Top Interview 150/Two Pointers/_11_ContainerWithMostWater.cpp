// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxArea;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    cout<<"The maximum amount of water a container can store will be : "<<solve.maxArea(height)<<endl;

    // 2nd Example
    height = {1,1};
    cout<<"The maximum amount of water a container can store will be : "<<solve.maxArea(height)<<endl;
}