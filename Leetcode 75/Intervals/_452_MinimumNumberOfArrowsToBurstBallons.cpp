// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons. Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path. Given the array points, return the minimum number of arrows that must be shot to burst all balloons.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int lastpoint = p[0][1];
        int ans = 1;
        for(auto point : p) {
            if(point[0] > lastpoint) {
                ans++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1],lastpoint);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int result = solution.findMinArrowShots(points);
    
    // Print the output
    cout << "Minimum number of arrows needed: " << result << endl;

    return 0;
}