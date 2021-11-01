#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>> rec;
        for(int r = 1;r<board.size()-1;r++){
            for(int c = 1;c<board[r].size()-1;c++){
                if(board[r][c]=='O'){
                    dfs(board,r,c,rec);
                    rec.clear();
                }
                
            }
        }
        int ans = 0;
    }
    bool dfs(vector<vector<char>>& board,int r ,int c,vector<pair<int,int>>& rec){
        if (r == 0 || r == board.size()-1 || c == 0 || c == board[r].size()-1)
        {
            
            for(auto p:rec){
                board[p.first][p.second]='O';
            }
            rec.clear();
            
            return false;
        }
        board[r][c] = 'X';
        rec.push_back({r,c});
        if (r - 1 >= 0 && board[r - 1][c] == 'O')
        {
            if(dfs(board, r - 1, c,rec)){

            }
            else{
                //board[r][c] = 'O';
                return false;
            }
        }
        if (r + 1 < board.size() && board[r + 1][c] == 'O')
        {
            if(dfs(board, r + 1, c,rec)){

            }
            else{
                //board[r][c] = 'O';
                return false;
            }
        }
        if (c - 1 >= 0 && board[r][c - 1] == 'O')
        {
            if(dfs(board, r, c - 1,rec)){

            }
            else{
                //board[r][c] = 'O';
                return false;
            }
        }
        if (c + 1 < board[r].size() && board[r][c + 1] == 'O')
        {
            if(dfs(board, r, c + 1,rec)){

            }
            else{
                //board[r][c] = 'O';
                return false;
            }
        }
        return true;
        
    }
};
int main(){
    vector<vector<char>> board = {
        {'O','X','X','O','X'},
        {'X','O','O','X','O'},
        {'X','O','X','O','X'},
        {'O','X','O','O','O'},
        {'X','X','O','X','O'}
    };
    Solution sol;
    sol.solve(board);
}






/*
Runtime: 12 ms, faster than 84.68% of C++ online submissions for Surrounded Regions.
Memory Usage: 24.8 MB, less than 5.06% of C++ online submissions for Surrounded Regions.



Input: board = [['X',"X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Input:
[
    ["O","X","X","O","X"],
    ["X","O","O","X","O"],
    ["X","O","X","O","X"],
    ["O","X","O","O","O"],
    ["X","X","O","X","O"]]
Output:
[
    ["O","X","X","O","X"],
    ["X","X","X","X","O"],
    ["X","X","X","O","X"],
    ["O","X","O","O","O"],
    ["X","X","O","X","O"]]

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.


*/