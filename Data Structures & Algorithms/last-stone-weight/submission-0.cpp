class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p_stones(stones.begin(), stones.end());
        while(p_stones.size() > 1) {
            int large = p_stones.top();
            p_stones.pop();
            int second_large = p_stones.top();
            p_stones.pop();
            int remaining = large - second_large;
            if(remaining != 0) p_stones.push(remaining);
        }
        if(not p_stones.empty()) return p_stones.top();
        return 0;
    }
};
