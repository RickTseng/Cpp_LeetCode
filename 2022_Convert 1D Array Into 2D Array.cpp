#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        vector<vector<int>> res(m,vector<int>(n,0));
        if(m*n!=original.size()){
            return res;
        }
        for(int i = 0;i<original.size();i++){
            res[i/n][i%n]=original[i];
        }
        return res;
    }
};
int main(){
    vector<int> n = {1,2,3,4};
    Solution sol;
    vector<vector<int>> ans = sol.construct2DArray(n,2,2);
}