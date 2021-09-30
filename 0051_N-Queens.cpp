#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution_v1{
    public:
        vector<vector<string>> solveNQueens(int n) {
            map<int,int> rowItem;
            map<int,int> colItem;
            for(int i = 0;i<n;i++){
                rowItem[i]=0;
                colItem[i]=0;
            }
            vector<vector<bool>> isExist(n, vector<bool>(n, false));
            vector<vector<string>> res;
            for(int i = 0;i<n;i++){
                int count = 0;
                dfs(isExist,rowItem,colItem,i,n,count,res);
            }
            return res;
        }
        void dfs(vector<vector<bool>>& isExist,
                map<int,int> rowItem,
                map<int,int> colItem,
                int index,int n,int count,
                vector<vector<string>>& res){
            if(index>=n*n){
                return;
            }
            int rowIndex = index / n;
            int columnIndex = index % n;
            if(judgeIncline(isExist,rowIndex,columnIndex,n)){
                return;
            }
            for(int i =0;i<n;i++){
                if(isExist[rowIndex][i]||isExist[i][columnIndex]){
                    return;
                }
            }
            isExist[rowIndex][columnIndex] = true;
            rowItem.erase(rowIndex);
            colItem.erase(columnIndex);           
            count++;
            if(count == n){
                vector<string> res_1;
                for(int i =0;i<n;i++){
                    string sr = "";
                    for(int j = 0;j<n;j++){
                        if(isExist[i][j]){
                            sr+="Q";
                        }
                        else{
                            sr+=".";
                        }
                    }
                    res_1.push_back(sr);
                }
                res.push_back(res_1);             
            }

            for(auto r:rowItem){
                for(auto c:colItem){
                    dfs(isExist,rowItem,colItem,r.first*n+c.first,n,count,res);
                }
            }
            isExist[rowIndex][columnIndex] = false;
            //rowItem[rowIndex]=0;
            //colItem[columnIndex]=0;
        }
        bool judgeIncline(vector<vector<bool>> isExist,int r,int c,int n){
            int jr = r+1;
            int jc = c-1;
            for(;jr<n && jc>=0 ;jr++,jc--){
                if(isExist[jr][jc]) return true;
            }
            jr = r+1;
            jc = c+1;
            for(;jr<n && jc<n ;jr++,jc++){
                if(isExist[jr][jc]) return true;
            }
            jr = r-1;
            jc = c-1;
            for(;jr>=0 && jc>=0 ;jr--,jc--){
                if(isExist[jr][jc]) return true;
            }
            jr = r-1;
            jc = c+1;
            for(;jr>=0 && jc<n ;jr--,jc++){
                if(isExist[jr][jc]) return true;
            }
            return false;
        } 
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> isExist(n, vector<bool>(n, false));
        vector<vector<string>> res;
        dfs(isExist,0,n,0,res);
        return res;
    }
    
    void dfs(vector<vector<bool>>& isExist,int index,int n,int count,vector<vector<string>>& res){
            if(index == n){
                vector<string> res_1;
                for(int i =0;i<n;i++){
                    string sr = "";
                    for(int j = 0;j<n;j++){
                        if(isExist[i][j]){
                            sr+="Q";
                        }
                        else{
                            sr+=".";
                        }
                    }
                    res_1.push_back(sr);
                }
                res.push_back(res_1);    
            }
            for(int c = 0;c<n;c++){
                if(!judgeIncline(isExist,index,c,n)){
                    isExist[index][c] = true;
                    count++;
                    dfs(isExist,index+1,n,count,res);
                    isExist[index][c] = false;
                }
            }
        }
        bool judgeIncline(vector<vector<bool>> isExist,int r,int c,int n){   
            for(int i =0;i<n;i++){
                if(isExist[i][c]){
                    return true;
                }
            }         
            int jr = r-1;
            int jc = c-1;
            for(;jr>=0 && jc>=0 ;jr--,jc--){
                if(isExist[jr][jc]) return true;
            }
            jr = r-1;
            jc = c+1;
            for(;jr>=0 && jc<n ;jr--,jc++){
                if(isExist[jr][jc]) return true;
            }
            return false;
        } 
};

int main(){
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(9);
}