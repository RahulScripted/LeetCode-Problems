// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours. Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return. Return the minimum integer k such that she can eat all the bananas within h hours.






#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(int speed,vector<int>&piles,int h){
        int n = piles.size();
        int count = 0;
        for(int i = 0;i < n;i++){
            if(count > h) return false;
            if(speed >= piles[i]) count++;
            else if(piles[i] % speed == 0) count += piles[i] / speed;
            else count += piles[i] / speed + 1;
        }
        if(count > h) return false;
        else return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        int ans = 1;
        for(int i = 0;i < n;i++){
            if(maxi < piles[i]) maxi = piles[i];
        }
        
        int lo = 1,hi = maxi;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(check(mid,piles,h)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }

};

int main(){
    Solution solve;

    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    vector<int>piles;
    cout<<"Give input : ";
    for(int i = 0;i < size;i++){
        int x;
        cin>>x;
        piles.push_back(x);
    }
    int h;
    cout<<"Enter no. of hours : ";
    cin>>h;
    cout<<"Minimum speed will be : "<<solve.minEatingSpeed(piles,h);
}