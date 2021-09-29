#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution{
    public:
    struct OneNightMap
    {
        map<char,int> valid = {
            {'1',0},
            {'2',0},
            {'3',0},
            {'4',0},
            {'5',0},
            {'6',0},
            {'7',0},
            {'8',0},
            {'9',0}
        };
    };
    bool TxTside(vector<vector<char>> board,int sR,int sC){
        OneNightMap v;
        for(int r = 0;r<3;r++){
            for(int c = 0;c<3;c++){
                if(board[sR+r][sC+c]!='.'){
                    v.valid[board[sR+r][sC+c]]++;
                    if(v.valid[board[sR+r][sC+c]]>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i =0;i<board.size();i++){
            OneNightMap vR;
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j]!='.'){
                    vR.valid[board[i][j]]++;
                    if(vR.valid[board[i][j]]>1){
                        return false;
                    }
                }
            }
            OneNightMap vC;
            for(int j = 0;j<board[i].size();j++){
                if(board[j][i]!='.'){
                    vC.valid[board[j][i]]++;
                    if(vC.valid[board[j][i]]>1){
                        return false;
                    }
                }
            }
        }
        for(int r = 0;r<9;r+=3){
            for(int c = 0;c<9;c+=3){
                if(!TxTside(board,r,c)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
int main(){
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };


    Solution sol;
    bool ans = sol.isValidSudoku(board);
}
//Runtime: 36 ms, faster than 14.44% of C++ online submissions for Valid Sudoku.
//Memory Usage: 25.2 MB, less than 5.00% of C++ online submissions for Valid Sudoku.