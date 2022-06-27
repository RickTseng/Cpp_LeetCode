#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i = 1;i<=n;i++){
            addFunc(i,n,k,res,tmp);
        }


        return res;
    }
    void addFunc(int crt ,int n,int k,vector<vector<int>> &res,vector<int> tmp){
        
        tmp.push_back(crt);
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        for(int _crt = crt+1;_crt<=n;_crt++){
            addFunc(_crt,n,k,res,tmp);
        }
        

    }
};
int main(){
    Solution sol;
    vector<vector<int>> ans = sol.combine(4,2);
}
/**
 * @brief 
 * vector<vector<int>>ans;
 * vector<int>tmp;
 *  void solve(int n,int k,int ind)
    {
        if(k==0)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=ind;i<=n;i++)
        {
            tmp.push_back(i);
            solve(n,k-1,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
    
        solve(n,k,1);
        return ans;
        
    }
 * 
 */