// Given an array of integers arr, replace each element with its rank. The rank represents how large the element is. The rank has the following rules:

// 1.  Rank is an integer starting from 1.

// 2.  The larger the element, the larger the rank. If two elements are equal, their rank must be the same.

// 3.  Rank should be as small as possible.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>a=arr;
        sort(a.begin(),a.end());
        unordered_map<int,int>mp;
        int i=0,n=arr.size(),rank=1;
        while(i<n){
            if(i!= 0 && (a[i]!= a[i-1])) rank++;
            mp[a[i]]=rank;
            i++;
        }
        for(auto &x:arr) x=mp[x];
        return arr;
    }
};

void display(vector<int>&arr){
    for(int i = 0;i < arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {40,10,20,30};
    cout<<"Our array : ";
    display(arr);
    vector<int>result = solve.arrayRankTransform(arr);
    cout<<"Rank of the array : ";
    display(result);

    // 2nd Example
    arr = {37,12,28,9,100,56,80,5,12};
    cout<<"Our array : ";
    display(arr);
    result = solve.arrayRankTransform(arr);
    cout<<"Rank of the array : ";
    display(result);
}