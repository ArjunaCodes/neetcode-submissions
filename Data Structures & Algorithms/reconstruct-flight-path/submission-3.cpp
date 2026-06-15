class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 1. Map to multiset keeps destinations sorted and allows duplicate flights
        unordered_map<string, multiset<string>> adj_travel;
        for (const auto& ticket : tickets) {
            adj_travel[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> itinerary;
        dfs("JFK", adj_travel, itinerary);
        
        // 2. The itinerary was built backwards, so we must reverse it
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(string airport, unordered_map<string, multiset<string>>& adj_travel, vector<string>& itinerary) {
        // Process all outgoing flights from the current airport
        while (!adj_travel[airport].empty()) {
            // Always pick the lexicographically smallest flight available
            auto next_destination_it = adj_travel[airport].begin();
            string next_dest = *next_destination_it;
            
            // Remove the ticket before moving to the next city
            adj_travel[airport].erase(next_destination_it);
            
            dfs(next_dest, adj_travel, itinerary);
        }
        
        // When an airport has no flights left, it's safe to append to the route
        itinerary.push_back(airport);
    }
};
