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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int sum = 0;
        for(auto c:candidates){
            sum+=c;
        }
        if(sum<target){
            return res;
        }
        if(sum==target){
            res.push_back(candidates);
            return res;
        }
        vector<int> tmp;
        dfs(candidates,0,tmp,res,target);
        return res;
    }
    void dfs(vector<int> candidates,int idx,vector<int> tmp,vector<vector<int>> &res,int target){
        if(target<0){
            return;
        }
        if(target==0){
            if(find(res.begin(),res.end(),tmp)==res.end()){
                res.push_back(tmp);
            }
            return;
        }
        for(;idx<candidates.size();idx++){
            tmp.push_back(candidates[idx]);
            dfs(candidates,idx+1,tmp,res,target-candidates[idx]);
            while (idx+1<candidates.size() && candidates[idx]==candidates[idx+1])
            {
                idx++;
            }
            
            tmp.pop_back();
        }

    }
};
/*
* [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
27
[c]
30
*/
int main(){
    vector<int> c = {10,1,2,7,6,1,5};
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(c,8);

}