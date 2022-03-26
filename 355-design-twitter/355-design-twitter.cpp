class Twitter {
public:
    
    unordered_map<int,vector<pair<int,int>>>t;
    unordered_map<int,set<int>>f;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({ time++ , tweetId });
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto i : t[userId]){
            pq.push(i);
        }
        for(auto i : f[userId]){
            for(auto j : t[i]){
                pq.push(j);
            }
        }
        vector<int>res;
        int k = 10;
        while(!pq.empty() && k--){
            pair<int,int>p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            f[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */