// Implement the RandomizedSet class:

// 1.  RandomizedSet() Initializes the RandomizedSet object.

// 2.  bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.

// 3.  bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.

// 4.  int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

// You must implement the functions of the class such that each function works in average O(1) time complexity.





#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {}

    bool search(int val) {
        return mp.find(val) != mp.end();
    }

    bool insert(int val) {
        if (search(val)) return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!search(val)) return false;
        auto it = mp.find(val);
        v[it->second] = v.back();
        mp[v[it->second]] = it->second;
        v.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

int main() {
    srand(time(0));  // Seed for random number generator

    RandomizedSet randomSet;

    // Test insertions
    cout << "Insert 1: " << (randomSet.insert(1) ? "Success" : "Already exists") << endl;
    cout << "Insert 2: " << (randomSet.insert(2) ? "Success" : "Already exists") << endl;
    cout << "Insert 3: " << (randomSet.insert(3) ? "Success" : "Already exists") << endl;

    // Test getRandom
    cout << "Random element: " << randomSet.getRandom() << endl;

    // Test removal
    cout << "Remove 1: " << (randomSet.remove(1) ? "Removed" : "Not found") << endl;
    cout << "Remove 4: " << (randomSet.remove(4) ? "Removed" : "Not found") << endl;

    // Test getRandom again
    cout << "Random element after removal: " << randomSet.getRandom() << endl;

    return 0;
}