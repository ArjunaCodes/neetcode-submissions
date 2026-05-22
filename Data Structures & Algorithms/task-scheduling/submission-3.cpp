class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto task: tasks) {
            mp[task]++;
        }
        priority_queue<int> pq;
        for(const auto& a: mp) {
            pq.push(a.second);
        }

        int result{0};
        while(not pq.empty()) {
            vector<int> temp;
            int size = 0;
            for(int i=0; i<n+1 and not pq.empty() ; ++i) {
                int value  = pq.top();
                temp.push_back(--value);
                pq.pop();
                ++size;
            }
            for(auto v: temp) {
                if(v > 0) {
                    pq.push(v);
                }
            }
            result += pq.empty()? size : n+1;
        }
        return result;
    }
};
