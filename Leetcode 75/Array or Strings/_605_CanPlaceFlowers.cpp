// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        for (int i = 0; i < flowerbed.size(); ++i){
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                if (--n == 0)
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution solve;

    // 1st example
    vector<int>flowerbed = {1,0,0,0,1};
    int n = 2;
    if(solve.canPlaceFlowers(flowerbed,n)) cout<<"Yes, we can place flowers"<<endl;
    else cout<<"No, we can't place flowers"<<endl;

    // 2nd example
    flowerbed = {1,0,0,0,1};
    n = 1;
    if(solve.canPlaceFlowers(flowerbed,n)) cout<<"Yes, we can place flowers"<<endl;
    else cout<<"No, we can't place flowers"<<endl;
}