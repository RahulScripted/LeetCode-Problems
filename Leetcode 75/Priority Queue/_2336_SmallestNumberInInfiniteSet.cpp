// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...]. Implement the SmallestInfiniteSet class:

// 1.  SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.

// 2.  int popSmallest() Removes and returns the smallest integer contained in the infinite set.

// 3.  void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
 




#include <iostream>
#include <set>
using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        constexpr int N = 1000;
        for (int i = 1; i <= N; ++i) {
            s.emplace(i);
        }
    }

    int popSmallest() {
        const int res = *s.begin();
        s.erase(s.begin());
        return res;
    }

    void addBack(int num) {
        s.emplace(num);
    }

private:
    set<int> s;
};

int main() {
    SmallestInfiniteSet infiniteSet;

    cout << "Pop smallest: " << infiniteSet.popSmallest() << endl;
    cout << "Pop smallest: " << infiniteSet.popSmallest() << endl;

    infiniteSet.addBack(1);
    cout << "Pop smallest after adding back 1: " << infiniteSet.popSmallest() << endl;
    cout << "Pop smallest: " << infiniteSet.popSmallest() << endl;
}