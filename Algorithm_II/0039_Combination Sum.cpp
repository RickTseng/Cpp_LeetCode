#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        build(candidates,target,0,tmp,res);
        

        return res;
    }
    void build(vector<int>& candidates,int target,int idx,vector<int> tmp,vector<vector<int>> &res){
        for(;idx<candidates.size();idx++){
            if(target - candidates[idx]<0){                
                return;
            }
            if(target - candidates[idx]== 0){
                tmp.push_back(candidates[idx]);
                res.push_back(tmp);
                return;
            }
            if(target - candidates[idx]>0){
                tmp.push_back(candidates[idx]);
                build(candidates,target - candidates[idx],idx,tmp,res);
                tmp.pop_back();
            }
            
        }
    }
};
int main(){
    vector<int> nums = {3,5,8};
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(nums,11);
}