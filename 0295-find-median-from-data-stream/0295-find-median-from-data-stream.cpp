#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxheap; 
    priority_queue<int, vector<int>, greater<int>> minheap; 

public:
    MedianFinder() {
    }

    void addNum(int num) {
        maxheap.push(num);

        
        if (!minheap.empty() && maxheap.top() > minheap.top()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size() > minheap.size()) {
            return maxheap.top();
        } else if (minheap.size() > maxheap.size()) {
            return minheap.top();
        } else {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
    }
};
