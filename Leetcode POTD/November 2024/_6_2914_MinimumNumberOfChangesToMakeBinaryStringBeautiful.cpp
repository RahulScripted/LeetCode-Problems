// You are given a 0-indexed binary string s having an even length. A string is beautiful if it's possible to partition it into one or more substrings such that:

// 1.  Each substring has an even length.

// 2.  Each substring contains only 1's or only 0's.

// 3.  You can change any character in s to 0 or 1.

// Return the minimum number of changes required to make the string s beautiful.






#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        for (int i = 0; i < s.size() - 1; i += 2) {
            if (s[i] != s[i + 1]) {
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution solve;

    string s = "1001";
    cout<<"Minimum changes required : "<<solve.minChanges(s)<<endl;
}