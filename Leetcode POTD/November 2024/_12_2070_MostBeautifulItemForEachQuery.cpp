// You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively. You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0. Return an array answer of the same length as queries where answer[j] is the answer to the jth query.





#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int maxI = INT_MAX;
        vector<vector<int>> res = {{0, 0, maxI}};

        sort(items.begin(), items.end());

        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            if (beauty > res.back()[1]) {
                res.back()[2] = price;
                res.push_back({price, beauty, maxI});
            }
        }

        vector<int> ans;

        for (int x : queries) {
            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i][0] <= x) {
                    ans.push_back(res[i][1]);
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Define sample items
    vector<vector<int>> items = {{1, 2}, {2, 4}, {3, 6}, {5, 8}, {10, 12}};
    
    // Define sample queries
    vector<int> queries = {2, 4, 10, 1, 6};

    // Get the result for the queries
    vector<int> result = solution.maximumBeauty(items, queries);

    // Print the result
    cout << "Maximum beauty for each query: ";
    for (int beauty : result) cout << beauty << " ";
    cout << endl;

    return 0;
}