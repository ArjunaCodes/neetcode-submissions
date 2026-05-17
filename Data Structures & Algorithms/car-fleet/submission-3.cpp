class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, float>> cars;
        for(int i=0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](auto a, auto b) {
            return a.first > b.first;
        });
        vector<float> time_to_reach;
        for(auto &[pos, speed]: cars) {
            time_to_reach.push_back(((target - pos)/speed));
        }
        stack<float> st;
        for(auto time: time_to_reach) {
            if(st.empty()) {
                // cout << time << " ";
                st.push(time);
                continue;
            }
            if(st.top() < time) {
                // cout << time << " ";
                st.push(time);
            }

        }

        return st.size();
    }
};
