#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10001,0);
        int maxN = 0;
        for(auto n:nums){
            dp[n]+=n;
            maxN = max(maxN,n);
        }
        vector<int> res(maxN+1,-1);
        return dfs(dp,maxN,res);
        
        
    }
    int dfs(vector<int>& nums,int index,vector<int>& res){
        if(index < 0){
             return 0;
        }      
        if(res[index] >= 0){
            return res[index];
        }
        res[index]=max(dfs(nums,index-1,res),dfs(nums,index-2,res)+nums[index]);
        return res[index];
        
    }
};
int main(){
    Solution sol;
    vector<int> nums = {8,10,4,9,1,3,5,9,4,10};
    int ans = sol.deleteAndEarn(nums);
}