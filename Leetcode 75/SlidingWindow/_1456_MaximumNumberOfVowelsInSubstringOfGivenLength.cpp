// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.





#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

    int maxVowels(string s, int k) {
        // Approach 2
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        
        int count = 0;
        for (int i = 0; i < k; i++) count += isVowel(s[i]);

        int maxCount = count;
        for (int right = k; right < s.size(); right++){
            count += isVowel(s[right]) - isVowel(s[right - k]);
            maxCount = max(maxCount, count);
        }
        return maxCount;

        // Approach 1
        // set<char>st={'a','e','i','o','u'};
        // int i=0,j=0;
        // int n=s.size();
        // int cnt=0;
        // int ans=0;
        // while(j<n){
        //     if(st.count(s[j])) cnt++;
        //     if(j-i+1==k){
        //         ans=max(ans,cnt);
        //         while(j-i+1>=k){
        //             if(st.count(s[i]))cnt--;
        //             i++;
        //         }
        //     }
        //   j++;

        // }
        // return ans;
    }
};

int main() {
    Solution solution;
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = solution.maxVowels(s, k);

    cout << "The maximum number of vowels in any substring of length " << k << " is: " << result << endl;

    return 0;
}