class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        int index = 0;
        for(const auto& crd: points) {
            pq.push({(pow(crd[0],2) + pow(crd[1],2)), index++});
        }
        vector<vector<int>> ans;
        while(k--) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
