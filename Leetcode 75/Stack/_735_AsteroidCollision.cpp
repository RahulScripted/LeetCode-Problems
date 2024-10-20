// We are given an array asteroids of integers representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed. Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.





#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack; 
        for(int &asteroid : asteroids) {
            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                int sum = asteroid + stack.back(); 
                if (sum < 0) stack.pop_back();
                else if (sum > 0) asteroid = 0;
                else {
                    stack.pop_back();
                    asteroid = 0; 
                }
            }

            if (asteroid != 0) stack.push_back(asteroid);
        }
        return stack;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = solution.asteroidCollision(asteroids1);
    cout << "Result for test case 1: ";
    for (int a : result1) cout << a << " ";
    cout << endl;

    // Test case 2
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = solution.asteroidCollision(asteroids2);
    cout << "Result for test case 2: ";
    for (int a : result2) cout << a << " ";
    cout << endl;

    // Test case 3
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = solution.asteroidCollision(asteroids3);
    cout << "Result for test case 3: ";
    for (int a : result3) cout << a << " ";
    cout << endl;

    // Test case 4
    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> result4 = solution.asteroidCollision(asteroids4);
    cout << "Result for test case 4: ";
    for (int a : result4) cout << a << " ";
    cout << endl;

    // Test case 5
    vector<int> asteroids5 = {-5, 5, -10, 10};
    vector<int> result5 = solution.asteroidCollision(asteroids5);
    cout << "Result for test case 5: ";
    for (int a : result5) cout << a << " ";
    cout << endl;

    return 0;
}