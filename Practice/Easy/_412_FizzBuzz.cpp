// Given an integer n, return a string array answer (1-indexed) where:

// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        for(int i = 1;i <= n;i++){
            if(i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
            else if(i % 3 == 0) ans.push_back("Fizz");
            else if( i % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};

void display(vector<string>&ans){
    int n = ans.size();
    for(int i = 0;i < n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st example
    int n = 3;
    vector<string>ans = solve.fizzBuzz(n);
    cout<<"Array for "<<n<<" : ";
    display(ans);

    // 2nd example
    n = 15;
    ans = solve.fizzBuzz(n);
    cout<<"Array for "<<n<<" : ";
    display(ans);

    // 3rd example
    n = 5;
    ans = solve.fizzBuzz(n);
    cout<<"Array for "<<n<<" : ";
    display(ans);
}