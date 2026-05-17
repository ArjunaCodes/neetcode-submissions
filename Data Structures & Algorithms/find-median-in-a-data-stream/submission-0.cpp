class MedianFinder {
    vector<int> numbers;
public:
    MedianFinder():numbers{} {
        
    }
    
    void addNum(int num) {
            numbers.push_back(num);
    }
    
    double findMedian() {
        int size = numbers.size();
        if(size == 1) return numbers[0];
        sort(numbers.begin(), numbers.end());
        if(size % 2 == 0) {
            return ((double)(numbers[size/2] + numbers[size/2 - 1]) / 2);
        }
        return numbers[size/2];
    }
};
