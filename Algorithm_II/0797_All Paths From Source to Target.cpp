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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> tmp;
        if(graph[0].empty()){
            return res;
        }
        tmp.push_back(0);
        dfs(graph,0,res,tmp);
        return res;
    }
    void dfs(vector<vector<int>>& graph,int target,vector<vector<int>> &res,vector<int> tmp){
        if(target == graph.size()-1){
            res.push_back(tmp);
            return;
        }
        if(graph[target].empty()){
            return;
        }
        for(auto g:graph[target]){
            tmp.push_back(g);
            dfs(graph,g,res,tmp);
            tmp.pop_back();
        }
    }
};
int main(){
    vector<vector<int>> graph = {{2},{},{1}};
    Solution sol;
    vector<vector<int>> ans = sol.allPathsSourceTarget(graph);
}