#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution_org{
    public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> _path;
        map<char, int> _board;
        map<char, int> _word;
        for(int r = 0;r<board.size();r++){
            for(int c = 0 ;c<board[r].size();c++){
                if(_board.find(board[r][c])==_board.end()){
                    _board[board[r][c]]=1;
                }
                else{
                    _board[board[r][c]]+=1;
                }
            }
        }
        for(auto s:word){
            if(_word.find(s)==_board.end()){
                _word[s]=1;
            }
            else{
                _word[s]+=1;
            }
        }
        for(auto s:word){
            if(_board.find(s)==_board.end()){
                return false;
            }
            if(_word[s]>_board[s]){
                return false;
            }
        }
        bool res = false;
        for(int r = 0;r<board.size();r++){
            for(int c = 0 ;c<board[r].size();c++){
                if(board[r][c]==word[0]){
                    findFunc(board,r,c,word,0,_path,res);
                    if(res){
                        return res;
                    }
                }
            }
        }
        return false;
    }
    void findFunc(vector<vector<char>>& board,int r,int c, string word,int index,vector<vector<int>> _path, bool& res){
        if(res){
            return;
        }
        vector<int> tmp = {r,c};
        if(find(_path.begin(),_path.end(),tmp)!=_path.end()){
            return;
        }
        _path.push_back(tmp);
        index++;
        if(index>word.size()-1){
            res = true;
            return;
        }
        char cur = word[index];
        if(c+1<board[r].size() && board[r][c+1]==word[index]){
            findFunc(board,r,c+1,word,index,_path,res);
        }
        if(r+1<board.size() && board[r+1][c]==word[index]){
            findFunc(board,r+1,c,word,index,_path,res);
        }
        if(c>0 && board[r][c-1]==word[index]){
            findFunc(board,r,c-1,word,index,_path,res);
        }
        if(r>0 && board[r-1][c]==word[index]){
            findFunc(board,r-1,c,word,index,_path,res);
        }

        return;
        
    }
};
class Solution{
    public:
    bool exist(vector<vector<char>>& board, string word){
        for(int r = 0;r<board.size();r++){
            for(int c = 0 ;c<board[r].size();c++){
                if(board[r][c]==word[0]){
                    if(dfs(board,r,c,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,int r,int c,int index, string word){
        if(index==word.size()){
            return true;
        }
        if(r<0||r>=board.size()||c<0||c>=board[0].size()){
            return false;
        }
        if(board[r][c]!=word[index]){
            return false;
        }
        char tmp = board[r][c];
        board[r][c] = '*';
        if(dfs(board,r-1,c,index+1,word)
        ||dfs(board,r+1,c,index+1,word)
        ||dfs(board,r,c-1,index+1,word)
        ||dfs(board,r,c+1,index+1,word)){
            return true;
        }
        board[r][c]=tmp;
    }
};
int main(){
    Solution sol;
    //vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board;
    for(int i = 0;i<6;i++){
        vector<char> tmp;
        for(int j = 0;j<6;j++){
            tmp.push_back('A');
        }
        board.push_back(tmp);
    }
    bool ans = sol.exist(board,"AAAAAAAAAAAAAAA");
    printf("program stop.\n");
}
//My first version V1.0.0 only solve 50/56
//Can't solve following : Time Limit Exceeded
//[["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","B"],["A","A","A","A","B","A"]]
//"AAAAAAAAAAAAABB"

//V1.0.1 ref web solution using mark visited char, so the function doesn't visited again.
//Runtime: 753 ms, faster than 12.46% of C++ online submissions for Word Search.
//Memory Usage: 7.5 MB, less than 40.82% of C++ online submissions for Word Search.