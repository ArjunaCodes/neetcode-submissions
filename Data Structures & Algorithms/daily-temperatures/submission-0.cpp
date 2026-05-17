class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> warm_tracker;
        int i = temperatures.size()-1;
        vector<int> warm_days(i+1, 0);
        for(i; i >=0; --i) {
            if(warm_tracker.empty()) {
                warm_tracker.push({temperatures[i], i});
            }
            else {
                while(not warm_tracker.empty() and warm_tracker.top().first <= temperatures[i]) {
                    warm_tracker.pop();
                }
                if(not warm_tracker.empty()) {
                    warm_days[i] = warm_tracker.top().second - i;
                }
                warm_tracker.push({temperatures[i], i});
            }
        }
        return warm_days;
    }
};
