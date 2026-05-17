class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";
        string value{""};
        const auto value_store = store[key];
        int left = 0, right = value_store.size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            // std::cout<< mid << " " << left << " " << right << " " << endl;
            if(timestamp > value_store[mid].first) {
                value = value_store[mid].second;
                left = mid + 1;
            }
            else if ( timestamp < value_store[mid].first) {
                right = mid - 1;
            }
            else {
                return value_store[mid].second;
            }
        }
        std::cout<<endl;
        return value;
    }
};
