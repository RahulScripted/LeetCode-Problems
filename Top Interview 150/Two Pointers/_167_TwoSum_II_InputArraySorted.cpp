// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length. Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int total = numbers[left] + numbers[right];
            if (total == target) return {left + 1, right + 1};
            else if (total > target) right--;
            else left++;
        }
        return {-1, -1};
    }
};

int main() {
    Solution solution;

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(numbers, target);

    if (result[0] != -1) cout << "Indices: " << result[0] << ", " << result[1] << endl;
    else cout << "No solution found!" << endl;
}