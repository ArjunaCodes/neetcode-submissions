class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    stack<pair<int, int>> posts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        const auto followee = following[userId];
        auto posts_copy = posts;
        while(feeds.size() < 10 and not posts_copy.empty()) {
            if(posts_copy.top().first == userId or followee.find(posts_copy.top().first) != followee.end()) {
                feeds.push_back(posts_copy.top().second);
            }
            posts_copy.pop();
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
