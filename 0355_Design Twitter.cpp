#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Ref GK_the_Boss
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Design Twitter.
// Memory Usage: 7.2 MB, less than 50.28% of C++ online submissions for Design Twitter.

class Twitter {
    vector<pair<int, int>> whoPosted;
    unordered_map<int, unordered_set<int>> whoFollowWho;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        whoPosted.push_back({ userId, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> s = whoFollowWho[userId];
        s.insert(userId);
        vector<int> ans;
        for (int i = whoPosted.size() - 1; i > -1 && ans.size() < 10; --i) if (s.find(whoPosted[i].first) != s.end()) ans.push_back(whoPosted[i].second);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        whoFollowWho[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        whoFollowWho[followerId].erase(followeeId);
    }
};