class Twitter {

private:

    int time;
    unordered_map<int , vector<pair<int,int>>> mpp; 
    unordered_map<int, set<int>> follow_user;

public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        mpp[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> maxheap;
        vector<int> ans;

        for(auto it : mpp[userId]){
            maxheap.push(it);
        }

        for( auto follower : follow_user[userId]){
            for(auto tweets : mpp[follower]){
                maxheap.push(tweets);
            }
        }

        for(int i=0;i<10;i++){
            if(maxheap.empty()) break;
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {

        follow_user[followerId].insert(followeeId);

    }
    
    void unfollow(int followerId, int followeeId) {
        if(follow_user[followerId].find(followeeId) != follow_user[followerId].end()){
            follow_user[followerId].erase(followeeId);
        }
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