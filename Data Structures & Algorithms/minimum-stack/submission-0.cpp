class MinStack {
public:
    vector<int> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.emplace_back(val);
    }
    
    void pop() {
        std::cout<<" POP  " << stk.back() << endl;
        stk.pop_back();
    }
    
    int top() {
        // std::cout<<" back " << stk.back() << endl;
        return stk.back();
    }
    
    int getMin() {
        int min_value = INT_MAX;
        for(const auto& in: stk) {
            min_value = min(min_value, in);
        }
        return min_value;
    }
};
