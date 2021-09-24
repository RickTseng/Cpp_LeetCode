#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class Solution_org{
    public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> tmp;
        for(int row = 0;row < grid.size();row++){
            vector<int> tmpR;
            for(int col = 0;col<grid[row].size();col++){
               tmpR.push_back(-1);
            }
            tmp.push_back(tmpR);
        }
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col<grid[row].size();col++){
                if(grid[row][col]=='1' && tmp[row][col]==-1){
                    if(count==0){
                        count=1;
                        tmp[row][col] = count;
                        dfs(tmp,grid,row,col,count);
                    }
                    else{
                        count++;
                        tmp[row][col] = count;
                        dfs(tmp,grid,row,col,count);
                    }       
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& tmp,vector<vector<char>> grid,int row,int col,int& count){
        if(row-1>=0 && grid[row-1][col]=='1' && tmp[row-1][col]==-1){
            tmp[row-1][col] = count;
            dfs(tmp,grid,row-1,col,count);
            
        }
        if(row+1<grid.size() && grid[row+1][col]=='1'&& tmp[row+1][col]==-1){
            tmp[row+1][col] = count;
            dfs(tmp,grid,row+1,col,count);
            
        }
        if(col-1>=0 && grid[row][col-1]=='1'&& tmp[row][col-1]==-1){
            tmp[row][col-1] = count;
            dfs(tmp,grid,row,col-1,count);
            
        }
        if(col+1<grid[row].size() && grid[row][col+1]=='1'&& tmp[row][col+1]==-1){
            tmp[row][col+1] = count;
            dfs(tmp,grid,row,col+1,count);
        }
    }
};
class Solution{
    public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col<grid[row].size();col++){
                if(grid[row][col]=='1' ){
                    count++;
                    dfs(grid,row,col);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,int row,int col){
        grid[row][col] = '0';
        if(row-1>=0 && grid[row-1][col]=='1' ){
            
            dfs(grid,row-1,col);
        }
        if(row+1<grid.size() && grid[row+1][col]=='1'){
            
            dfs(grid,row+1,col);
        }
        if(col-1>=0 && grid[row][col-1]=='1'){
            
            dfs(grid,row,col-1);
            
        }
        if(col+1<grid[row].size() && grid[row][col+1]=='1'){
            
            dfs(grid,row,col+1);
        }
    }
};
int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','1'},
        {'1','0','0','1','1'},
        {'1','0','1','1','1'},
        {'1','0','0','0','1'},
        {'1','1','1','1','1'}
    };
    vector<vector<char>> grid2;
    for(int i = 0 ;i<300;i++){
        vector<char> tmp;
        for(int j = 0; j<300;j++){
            if(i%2){
                tmp.push_back('1');
            }
            else{
                tmp.push_back('0');
            }
        }
        grid2.push_back(tmp);
    }
    Solution sol;
    int ans = sol.numIslands(grid2);
    printf("End\n");
}
//Org version can't solve element more than 300*300
//Runtime: 32 ms, faster than 39.73% of C++ online submissions for Number of Islands.
//Memory Usage: 12.2 MB, less than 40.56% of C++ online submissions for Number of Islands.