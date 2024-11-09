// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index. According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) return n - i;
        }

        return 0;
    }
};

int main() {
    Solution solution;
    
    int n;
    cout << "Enter the number of papers: ";
    cin >> n;

    vector<int> citations(n);
    cout << "Enter the citation counts: ";
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    int result = solution.hIndex(citations);
    cout << "The H-Index is: " << result << endl;

    return 0;
}