// You are given an integer num. You can swap two digits at most once to get the maximum valued number. Return the maximum valued number you can get.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        
        return num;
    }
};

int main() {
    Solution solution;
    int num = 2736;
    int result = solution.maximumSwap(num);
    cout << "Maximum number after swap: " << result << endl;
    return 0;
}