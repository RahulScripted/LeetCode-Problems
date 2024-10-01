// Given an array of integers arr of even length n and an integer k. We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.Return true If you can find a way to do that or false otherwise.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) rem += k;
            freq[rem]++;
        }
        
        if (freq[0] % 2 != 0) return false;
        
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) return false;
        }
        
        return true;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {1,2,3,4,5,10,6,7,8,9};
    int k = 5;
    if(solve.canArrange(arr,k)) cout<<"There is a way"<<endl;
    else cout<<"There is no way"<<endl;

    // 2nd Example
    arr = {1,2,3,4,5,6};
    k = 10;
    if(solve.canArrange(arr,k)) cout<<"There is a way"<<endl;
    else cout<<"There is no way"<<endl;
}