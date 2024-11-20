// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int count = 2;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tp = 2;
                for (int k = 0; k < n; k++) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    if (((y2 - y1) * (x3 - x1)) == ((y3 - y1) * (x2 - x1)) && (k != i) && (k != j)) {
                        tp++;
                    }
                }
                count = max(tp, count);
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    int result = solution.maxPoints(points);
    cout << "Maximum points on a line: " << result << endl;

    points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << "Maximum points on a line: " << solution.maxPoints(points) << endl;

    return 0;
}