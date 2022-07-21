#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;

// Ref VinayKumar03
// Runtime: 169 ms, faster than 31.89% of C++ online submissions for Task Scheduler.
// Memory Usage: 43.9 MB, less than 19.01% of C++ online submissions for Task Scheduler.

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // another approach is to use the heap for this process
        // we will go till a length of n in every iteration in our process
        // we will take the help of map for storing the count of every element
        unordered_map<char, int> mp;
        int ans = 0;
        for (int it : tasks)
            mp[it]++;
        priority_queue<int> mx;
        for (auto it : mp)
            mx.push(it.second);

        // we will work on our heap, where every element will be used after a span of n

        while (!mx.empty())
        {
            vector<int> temp;
            for (int i = 0; i <= n; i++)
            {
                if (!mx.empty())
                {
                    temp.push_back(mx.top());
                    mx.pop();
                }
            }
            for (int it : temp)
            {
                if (--it > 0)
                    mx.push(it);
            }
            ans += (mx.empty() ? temp.size() : n + 1);
        }
        return ans;
    }
};
int main(){
    vector<char> tasks = {'A','A','A','A','B','C','D','E','B'};
    Solution sol;
    int ans = sol.leastInterval(tasks,2);
}