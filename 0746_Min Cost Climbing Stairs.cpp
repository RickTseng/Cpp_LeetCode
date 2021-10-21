#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        cost.push_back(0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<dp.size();i++){
            dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }
        return dp[dp.size()-1];
    }
};
int main(){
    Solution sol;
    vector<int> cost = {10,15,20};
    int ans = sol.minCostClimbingStairs(cost);
}

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999


Runtime: 16 ms, faster than 11.43% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.9 MB, less than 22.16% of C++ online submissions for Min Cost Climbing Stairs.
Next challenges:

*/