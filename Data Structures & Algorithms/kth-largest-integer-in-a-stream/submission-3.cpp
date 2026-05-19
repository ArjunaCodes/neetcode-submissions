class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for(const auto& num: nums) {
            pq.emplace(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.emplace(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
