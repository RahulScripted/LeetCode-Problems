// You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k. For chosen indices i0, i1, ..., ik - 1, your score is defined as: The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2. It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]). Return the maximum possible score.






#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& speed, vector<int>& efficiency, int k) {
        int n = speed.size();
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i) ess[i] = {efficiency[i], speed[i]};

        sort(rbegin(ess), rend(ess));
        long long sumS = 0, res = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (auto& [e, s] : ess) {
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) res = max(res, sumS * e);
        }
        return res;
    }
};

int main() {
    Solution solution;

    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 3;

    long long result = solution.maxScore(speed, efficiency, k);
    cout << "Maximum score: " << result << endl;

    return 0;
}