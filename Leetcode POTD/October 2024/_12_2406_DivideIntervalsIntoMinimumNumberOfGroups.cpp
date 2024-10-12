// You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti]. You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other. Return the minimum number of groups you need to make.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_times, end_times;

        // Extract start and end times
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        // Sort start and end times
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int end_ptr = 0, group_count = 0;

        // Traverse through the start times
        for (int start : start_times) {
            if (start > end_times[end_ptr]) end_ptr++;
            else group_count++;
        }

        return group_count;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<vector<int>> intervals = {{5,10},{6,8},{1,5},{2,3},{1,10}};
    cout<<"Minimum groups will be : "<<solve.minGroups(intervals)<<endl;
}