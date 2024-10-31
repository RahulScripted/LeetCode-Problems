// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values. Implement the MedianFinder class:

// 1.  MedianFinder() initializes the MedianFinder object.

// 2.  void addNum(int num) adds the integer num from the data stream to the data structure.

// 3.  double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.




#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) 
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder medianFinder;

    // Example usage
    medianFinder.addNum(1);
    cout << "Median after adding 1: " << medianFinder.findMedian() << endl;
    
    medianFinder.addNum(2);
    cout << "Median after adding 2: " << medianFinder.findMedian() << endl;
    
    medianFinder.addNum(3);
    cout << "Median after adding 3: " << medianFinder.findMedian() << endl;

    return 0;
}
