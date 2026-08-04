class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>>tweets;
    unordered_map<int, unordered_set<int>>following;
    int time;
    int k;
    Twitter() {
        time=0;
        k=10;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>pq;
        // TO SEE USERS OWN TWEETS:
        //ek user id k kai tweet pairs(time and tweetId) possible hai.
        //auto iterate krenge over tweets of given userId.
        // use & to not create a copy , but use a reference instead.
        // and push the pairs <time, tweetId> in heap.
        for(auto& it:tweets[userId]) pq.push(it);
        
        // TO SEE TWEETS OF PEOPLE USER FOLLOWS (HIS FOLLOWEES):
        // we have already stored all the followees of the follower user in            'following map'
        // now to get the tweets by the followees we will use a nested for loop.
        // go over following[userId] to see all the followeeId there
        // now for each followeeId we find their tweets in 'tweets' map
        // just like we did earlier with finding users own tweets.
        for(int followees : following[userId]){
            for(auto& it : tweets[followees]) pq.push(it);
        }
            int cnt=0;
            vector<int>ans;
            while(!pq.empty() && cnt<k){
                ans.push_back(pq.top().second);
                pq.pop();
                cnt++;
            }
            return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
