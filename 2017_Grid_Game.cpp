#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
class Solution{
    public:
    long long gridGame(vector<vector<int>>& grid) {
        long long btmMax = 0;
        long long topCount = 0;
        long long res = INT64_MAX;
        for(int i = grid[0].size()-1;i>0;i--){        
            topCount+=grid[0][i];      
        }
        for(int i = 0;i<grid[0].size();i++){
            res = min(max(btmMax,topCount),res);
            if(i+1>=grid[0].size()){
                break;
            }
            topCount-=grid[0][i+1];
            btmMax+=grid[1][i];
        }
        return res;
    }
    void dfs(vector<vector<int>> grid,int r, int c,long long count,long long& _max,priority_queue<pair<long long,long long> >& qu){
        if(r>1 && c>=grid[r].size()){
            return;
        }
        count+=grid[r][c];
        grid[r][c] = 0;
        if(r==1&&c==grid[r].size()-1){
            _max = max(_max,count);
            long long secCount = 0;
            long long secMax = -1;
            //secondRobot(grid,0,0,secCount,secMax);
            pair<long long,long long> one_cd = {count,secMax};
            qu.push(one_cd);
            return;
        }
        if(r==0 && c==grid[r].size()-1){
            dfs(grid,1,c,count,_max,qu);
            return;
        }
        dfs(grid,r,c+1,count,_max,qu);
        dfs(grid,r+1,c,count,_max,qu);
    }
    void secondRobot(vector<vector<int>> grid,int r, int c,long long count,long long& _max){
        if(r>1 && c>=grid[r].size()){
            return;
        }
        count+=grid[r][c];
        if(r==1&&c==grid[r].size()-1){
            _max = max(_max,count);
            return;
        }
        if(r==0 && c==grid[r].size()-1){
            secondRobot(grid,1,c,count,_max);
            return;
        }
        secondRobot(grid,r,c+1,count,_max);
        secondRobot(grid,r+1,c,count,_max);
    }

};
int main(){
    vector<vector<int>> grid = {
        //case 5 ans:63
        //{20,3,20,17,2,12,15,17,4,15},
        //{20,10,13,14,15,5,2,3,14,3}

        //case 91 ans:44
        //{18,6,19,3,10,11,2,16,5},
        //{2,11,15,20,19,3,16,6,5}

        //{1,3,1,15},
        //{1,3,3,1}
        {3,3,1},
        {8,5,2}
    };
    /*
    for(int i =0;i<50000;i++){
        grid[0].push_back(i+1);
        grid[1].push_back(i+1);
    }
    */
    Solution sol;
    long long ans = sol.gridGame(grid);
    printf("finished");
}
//Runtime: 148 ms, faster than 100.00% of C++ online submissions for Grid Game.
//Memory Usage: 62.8 MB, less than 91.67% of C++ online submissions for Grid Game.