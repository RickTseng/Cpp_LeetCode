#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std; 
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n = mat[0].size();
        if(r * c != m * n){
            return mat;
        }
        vector<vector<int>> res(r,vector<int>(c,0));
        int idx = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                res[idx/c][idx%c] = mat[i][j];
                idx++;
            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> mat = {{1,2},{3,4}};
    Solution sol;
    vector<vector<int>> ans = sol.matrixReshape(mat,1,4);
}