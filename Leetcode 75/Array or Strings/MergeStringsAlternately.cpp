// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string. Return the merged string.



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int iteratorOfFirst = 0,iteratorOfSecond = 0,iteratorOfMerge = 0;
        string ans = "";
        int lengthOfFirstString = word1.size();
        int lengthOfSecondString = word2.size();

        // Merging
        while(iteratorOfFirst < lengthOfFirstString && iteratorOfSecond < lengthOfSecondString){
            if(iteratorOfMerge % 2 == 0){
                ans += word1[iteratorOfFirst];
                iteratorOfMerge++;
                iteratorOfFirst++;
            }
            else{
                ans += word2[iteratorOfSecond];
                iteratorOfMerge++;
                iteratorOfSecond++;
            }
        }

        // If 1st string has more length than 2nd string
        while(iteratorOfFirst < lengthOfFirstString){
           ans += word1[iteratorOfFirst];
            iteratorOfMerge++;
            iteratorOfFirst++;
        }

        // If 2nd string has more length than 1st string
        while(iteratorOfSecond < lengthOfSecondString){
           ans += word2[iteratorOfSecond];
            iteratorOfMerge++;
            iteratorOfSecond++;
        }
        
        // Finally return
        return ans;
    }
};

int main(){
    Solution solve;
    string word1 = "abc";
    string word2 = "pqr";

    cout<<"First string : "<<word1<<endl;
    cout<<"Second string : "<<word2<<endl;
    cout<<"Merged String : "<<solve.mergeAlternately(word1,word2)<<endl;
}