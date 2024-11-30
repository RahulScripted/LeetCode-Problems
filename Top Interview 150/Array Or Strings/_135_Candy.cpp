// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings. You are giving candies to these children subjected to the following requirements:

// 1.  Each child must have at least one candy.

// 2.  Children with a higher rating get more candies than their neighbors.

// Return the minimum number of candies you need to have to distribute the candies to the children.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
        int totalCandies = n;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int currentPeak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                currentPeak++;
                totalCandies += currentPeak;
                i++;
            }

            if (i == n) return totalCandies;

            int currentValley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                currentValley++;
                totalCandies += currentValley;
                i++;
            }
            totalCandies -= min(currentPeak, currentValley);
        }
        return totalCandies;        
    }
};

int main() {
    vector<int> ratings = {1, 0, 2};

    Solution solution;
    int totalCandies = solution.candy(ratings);
    cout << "Minimum number of candies required: " << totalCandies << endl;
}