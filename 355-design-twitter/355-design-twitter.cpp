class Twitter {
public:
    unordered_map<int,set<int>>follow1;
    unordered_map<int,vector<pair<int,int>>>post;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(post.find(userId)!=post.end()){
            post[userId].push_back({time++ , tweetId});
        }else{
            vector<pair<int,int>>t;
            t.push_back({time++, tweetId});
            post[userId] = t;
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto i : post[userId]){
            pq.push(i);
        }
        for(auto i : follow1[userId]){
            for(auto j : post[i]){
                pq.push(j);
            }
        }
        int k = 10;
        vector<int>res;
        while(!pq.empty() && k ){
            pair<int,int>p = pq.top();
            pq.pop();
            res.push_back(p.second);
            k-=1;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follow1[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow1[followerId].erase(followeeId);
    }
};
