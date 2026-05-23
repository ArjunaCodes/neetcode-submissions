class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> max_heap_smaller;
    priority_queue<int, vector<int>, greater<int>> min_heap_larger;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap_smaller.push(num);
        if(not min_heap_larger.empty() and max_heap_smaller.top() > min_heap_larger.top()) {
            min_heap_larger.push(num);
            max_heap_smaller.pop();
        }
        if(max_heap_smaller.size() > min_heap_larger.size() + 1) {
            min_heap_larger.push(max_heap_smaller.top());
            max_heap_smaller.pop();
        }
        if(min_heap_larger.size() > max_heap_smaller.size() + 1) {
            max_heap_smaller.push(min_heap_larger.top());
            min_heap_larger.pop();
        }
    }
    
    double findMedian() {
        if(max_heap_smaller.size() == min_heap_larger.size()) {
            return (max_heap_smaller.top() + min_heap_larger.top()) / 2.0;
        }
        if(max_heap_smaller.size() < min_heap_larger.size()) {
            return min_heap_larger.top();
        }
        else {
            return max_heap_smaller.top();
        }
    }
};
