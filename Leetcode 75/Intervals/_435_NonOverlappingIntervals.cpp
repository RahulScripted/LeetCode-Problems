// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end > intervals[i][0]) res++;
            else prev_end = intervals[i][1];
        }

        return res;     
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = solution.eraseOverlapIntervals(intervals);
    
    // Print the output
    cout << "Minimum number of intervals to remove for no overlap: " << result << endl;
}