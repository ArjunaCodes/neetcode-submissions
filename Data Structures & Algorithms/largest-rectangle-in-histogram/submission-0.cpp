class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int right = 0;
        int size  = heights.size();
        int max_area = 0;
        while(right < size) {
            if(st.empty()) {
                st.push({right, heights[right]});
                continue;
            }
            int last_index = right;
            while(not st.empty() and st.top().second >= heights[right]){
                auto [index, height] = st.top();
                max_area = max((right - index) * height, max_area);
                last_index = index;
                st.pop();
            }
            st.push({last_index, heights[right]});
            ++right;
        }
        while(not st.empty()) {
            auto [index, height] = st.top();
            max_area = max((size - index) * height, max_area);
            st.pop();
        }
        return max_area;
    }
};
