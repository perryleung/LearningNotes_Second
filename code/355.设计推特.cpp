/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 *
 * https://leetcode-cn.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (40.83%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 48K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
 * 
 * 
 * postTweet(userId, tweetId): 创建一条新的推文
 * getNewsFeed(userId):
 * 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
 * follow(followerId, followeeId): 关注一个用户
 * unfollow(followerId, followeeId): 取消关注一个用户
 * 
 * 
 * 示例:
 * 
 * 
 * Twitter twitter = new Twitter();
 * 
 * // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1关注了用户2.
 * twitter.follow(1, 2);
 * 
 * // 用户2发送了一个新推文 (推文id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
 * // 推文id6应当在推文id5之前，因为它是在5之后发送的.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1取消关注了用户2.
 * twitter.unfollow(1, 2);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * // 因为用户1已经不再关注用户2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */

// @lc code=start
static int globalTime = 0;
struct Tweet {
    int id;
    int time;
    Tweet *next;
    Tweet(int _id, int _time) : id(_id), time(_time) {
        next = nullptr;
    }
};
class User {
public:
    int id;
    Tweet *tweet_head;
    unordered_set<int> follows;
    User(int _id) : id(_id) {
        tweet_head = nullptr;
        follows.clear();
        follows.insert(id);
    }
    void follow(int userId) {
        if(userId != id)
            if(!follows.count(userId))
                follows.insert(userId);
    }
    void unfollow(int userId) {
        if(userId != id)
            if(follows.count(userId))
                follows.erase(userId);
    }
    void postTweet(int tweetId) {
        Tweet *tw = new Tweet(tweetId, ++globalTime);
        tw->next = tweet_head;
        tweet_head = tw;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        idToUser.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!idToUser.count(userId))
            idToUser[userId] = new User(userId);
        idToUser[userId]->postTweet(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(!idToUser.count(userId))
           return {};
        auto cmp = [&](const auto *a, const auto *b) {
            return a->time < b->time;
        };
        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> minHeap(cmp);
        for(const auto& followee : idToUser[userId]->follows) {
            if(!idToUser.count(followee))
                continue;
            Tweet *tw = idToUser[followee]->tweet_head;
            if(!tw)
                continue;
            minHeap.push(tw);
        }
        vector<int> res;
        while(!minHeap.empty()) {
            Tweet *tw = minHeap.top();
            minHeap.pop();
            res.push_back(tw->id);
            if(res.size() == 10)
                return res;
            if(tw->next)
                minHeap.push(tw->next);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!idToUser.count(followerId))
            idToUser[followerId] = new User(followerId);
        idToUser[followerId]->follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(!idToUser.count(followerId))
            idToUser[followerId] = new User(followerId);
        idToUser[followerId]->unfollow(followeeId);
    }
private:
    unordered_map<int, User*> idToUser;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

