// You have a RecentCounter class which counts the number of recent requests within a certain time frame.Implement the RecentCounter class:

// 1.  RecentCounter() Initializes the counter with zero recent requests.

// 2.  int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].






#include <iostream>
#include <vector>

using namespace std;

class RecentCounter {
private:
    vector<int> records;
    int start;

public:
    RecentCounter() : start(0) {}

    int ping(int t) {
        records.push_back(t);
        while (records[start] < t - 3000) start++;
        return records.size() - start;
    }
};

int main() {
    RecentCounter* counter = new RecentCounter();
    vector<int> timestamps = {1, 100, 3001, 3002};

    // Call ping and print results
    for (int t : timestamps) {
        cout << "Ping at " << t << ": " << counter->ping(t) << endl;
    }

    // Clean up
    delete counter;
}