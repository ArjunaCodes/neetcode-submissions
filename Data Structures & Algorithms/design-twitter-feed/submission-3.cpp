class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    list<pair<int, int>> posts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> recent_tweets;
        const auto& user_follows = following[userId];
        for(const auto& tweet: posts) {
            if(userId == tweet.first or user_follows.find(tweet.first) != user_follows.end()) {
                recent_tweets.push_back(tweet.second);
            }
            if(recent_tweets.size() >= 10){
                break;
            }
        }
        return recent_tweets;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
