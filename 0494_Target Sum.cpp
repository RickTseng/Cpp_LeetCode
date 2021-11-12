#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution_dfs {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int _sum = 0;
        dfs(nums,0,count,target);
        return count;
    }
    void dfs(vector<int> nums,int index,int& count,int _sum){
        if(index == nums.size()){
            if(_sum==0){
                count++;
            }
        }
        else{
            dfs(nums,index+1,count,_sum - nums[index]);
            dfs(nums,index+1,count,_sum + nums[index]);
        }
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> dpSum = {{0,1}};
        int index = 0;
        while (index<nums.size())
        {
            map<int,int> tmpDPSum;
            for(auto d:dpSum){
                if(tmpDPSum.find(d.first + nums[index])==tmpDPSum.end()){
                    tmpDPSum[d.first + nums[index]]=d.second;
                }
                else{
                    tmpDPSum[d.first + nums[index]]+=d.second;
                }
                if(tmpDPSum.find(d.first - nums[index])==tmpDPSum.end()){
                    tmpDPSum[d.first - nums[index]]=d.second;
                }
                else{
                    tmpDPSum[d.first - nums[index]]+=d.second;
                }

            }
            dpSum = tmpDPSum;
            index++;
        }
        return dpSum[target];
    }
};   
int main(){
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    Solution sol;
    int ans = sol.findTargetSumWays(nums,3);
}
/*
Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

Runtime: 248 ms, faster than 38.63% of C++ online submissions for Target Sum.
Memory Usage: 55 MB, less than 17.83% of C++ online submissions for Target Sum.
*/