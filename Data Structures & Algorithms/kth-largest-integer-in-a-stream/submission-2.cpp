class KthLargest {
    vector<int> elements;
    int k; 
public:
    KthLargest(int k, vector<int>& nums):k(k) {
        for(const auto& num: nums) {
            elements.push_back(num);
        }
        sort(elements.begin(), elements.end(), greater<int>());
        while(elements.size() > k) {
            elements.pop_back();
        }
    }
    
    int add(int val) {
        if(elements.size() == k and val < elements[k-1]) return elements[k-1];
        elements.emplace_back(val);
        sort(elements.begin(), elements.end(), greater<int>());
        if(elements.size() > k)
            elements.pop_back();
        return elements[k-1];
    }
};
