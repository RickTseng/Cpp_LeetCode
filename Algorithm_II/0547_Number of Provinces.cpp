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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        vector<int> rc(isConnected.size(),0);
        int mark = 1;
        for(int i =0;i<isConnected.size();i++){
            if(rc[i]==0){
                rc[i] = mark;
                dfs(i,isConnected,rc,mark);
                mark++;
            }
            
        }
        return mark-1;
    }
    void dfs(int t,vector<vector<int>> determine,vector<int> &rc,int mark)
    {
        for(int i = 0;i<determine.size();i++){
            if(i!=t && rc[i]==0 && determine[i][t]==1){
                rc[i] = mark;
                dfs(i,determine,rc,mark);
            }
        }
    }
};
int main(){
    vector<vector<int>> a = {
        {1,0,0,1},
        {0,1,0,1},
        {0,0,1,0},
        {1,1,0,1}
    };
    Solution sol;
    int ans = sol.findCircleNum(a);
}