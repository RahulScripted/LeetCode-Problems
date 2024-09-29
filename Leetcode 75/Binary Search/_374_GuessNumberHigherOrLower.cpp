// We are playing the Guess Game. The game is as follows:

// 1.  I pick a number from 1 to n. You have to guess which number I picked.

// 2.  Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

// 3.  You call a pre-defined API int guess(int num), which returns three possible results:

// 4.  -1: Your guess is higher than the number I picked (i.e. num > pick).

// 5.  1: Your guess is lower than the number I picked (i.e. num < pick).

// 6.  0: your guess is equal to the number I picked (i.e. num == pick).

// Return the number that I picked.





#include<bits/stdc++.h>
using namespace std;

int guess(int pickNumber){
    std::srand(std::time(0)); 
    int random_num = std::rand() % 20 + 1; 
    if(pickNumber == random_num) return 0;
    else if(pickNumber > random_num) return -1;
    else return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1,high = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(guess(mid) == -1) high = mid;
            else if(guess(mid) == 0) return mid;
            else low = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution solve;

    // 1st Example
    int n;
    cout<<"Pick a number from 1 to 20 : ";
    cin>>n;
    cout<<"Picked number : "<<solve.guessNumber(n)<<endl;

    // 2nd Example
    cout<<"Pick a number from 1 to 20 : ";
    cin>>n;
    cout<<"Picked number : "<<solve.guessNumber(n)<<endl;
}