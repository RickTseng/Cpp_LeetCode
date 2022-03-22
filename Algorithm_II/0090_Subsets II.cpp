#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(nums.begin(),nums.end());
        dfs(nums,0,res,tmp);
        return res;
    }
    void dfs(vector<int> nums,int idx,vector<vector<int>> &res, vector<int> tmp)
    {
        if(idx>=nums.size()){
            return;
        }
        for(;idx<nums.size();idx++){
            tmp.push_back(nums[idx]);
            if(find(res.begin(),res.end(),tmp)==res.end()){
                res.push_back(tmp);
            }
            dfs(nums,idx+1,res,tmp);
            tmp.pop_back();
        }
    }
};