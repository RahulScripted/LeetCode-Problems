// Given an array of characters chars, compress it using the following algorithm:

// 1.  Begin with an empty string s. For each group of consecutive repeating characters in chars:

// 2.  If the group's length is 1, append the character to s.

// 3.  Otherwise, append the character followed by the group's length.


// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars. After you are done modifying the input array, return the new length of the array.






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int checkAdjacent(vector<char> c, int i) {
        if (i >= c.size()) return 0;
        char ch = c[i];
        int len = 0;
        while (i < c.size() && c[i] == ch) {
            len++;
            i++;
        }
        return len;
    }

    int compress(vector<char>& chars) {
        int len = chars.size();
        int i = 0, j = 0;
        while (i < len) {
            chars[j] = chars[i];
            int count = checkAdjacent(chars, i);
            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[++j] = digit;
                }
            }
            i += count;
            j++;
        }
        chars.resize(j);
        return chars.size();
    }
};

int main() {
    Solution solution;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    cout << "Original array: ";
    for (char ch : chars) cout << ch << " ";

    cout << endl;

    int newSize = solution.compress(chars);
    cout << "Compressed array: ";
    for (char ch : chars) cout << ch << " ";
    cout << endl;
    
    cout << "New size: " << newSize << endl;
    
    return 0;
}