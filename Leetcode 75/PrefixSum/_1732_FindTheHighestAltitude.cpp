// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0. You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>pref(n+1,0);
        pref[0] = gain[0];
        for(int i = 1; i < n; i++) pref[i] = pref[i-1] + gain[i];
        return *max_element(pref.begin(), pref.end());
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>gain = {-5,1,5,0,-7};
    cout<<"Highest altitude : "<<solve.largestAltitude(gain)<<endl;

    // 2nd Example
    gain = {-4,-3,-2,-1,4,3,2};
    cout<<"Highest altitude : "<<solve.largestAltitude(gain)<<endl;
}