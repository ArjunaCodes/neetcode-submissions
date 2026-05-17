class Twitter {
    
    unordered_map<int, unordered_set<int>> user_follow;
    list<pair<int, int>> user_id_tweet;
public:
    Twitter():user_follow{}, user_id_tweet{} {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_id_tweet.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> recent_tweets;
        const auto& user_follows = user_follow[userId];
        for(const auto& tweet: user_id_tweet) {
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

        user_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(user_follow.find(followerId) != user_follow.end()) {
            user_follow[followerId].erase(followeeId);
        }
    }
};
