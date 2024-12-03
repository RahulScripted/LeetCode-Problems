// You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index. Return the modified string after the spaces have been added.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int m = spaces.size(), n = s.size();
        string t(n + m, ' ');
        
        int j = 0; 
        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                t[i+j] = ' '; 
                j++;  
            }
            t[i+j]=s[i];
        }
        return t;
    }
};

int main() {
    Solution solution;
    
    string s = "leetcodeisawesome";
    vector<int> spaces = {8, 13};
    
    string result = solution.addSpaces(s, spaces);
    
    cout << "Original string: " << s << endl;
    cout << "Spaces indices: ";
    for (int index : spaces) cout << index << " ";
    cout << endl;
    cout << "String after adding spaces: " << result << endl;
}