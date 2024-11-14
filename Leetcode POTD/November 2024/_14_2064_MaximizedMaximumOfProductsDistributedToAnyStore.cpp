// You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type. You need to distribute all products to the retail stores following these rules:

// 1.  A store can only be given at most one product type but can be given any amount of it.

// 2.  After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.

// Return the minimum possible x.






#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPossible(int x, vector<int>& quantities, int n) {
        double sum = 0;
        for (auto u : quantities) sum += ceil(u * 1.0 / x * 1.0);
        return sum > n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isPossible(mid, quantities, n)) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    Solution solution;

    int n = 6;
    vector<int> quantities = {11, 6, 8};
    int result = solution.minimizedMaximum(n, quantities);
    cout << "The minimized maximum quantity is: " << result << endl;
}