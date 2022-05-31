#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        vector<int> tb(100001,0);
        tb[0] = 0;
        tb[1] = 0;
        tb[2] = 1;
        tb[3] = 1;
        tb[4] = 2;
        for(int i = 5;i<dp.size();i++)
        {
            tb[i] = 1 + min(tb[i-3],tb[i-2]);
        }
        for(auto t:tasks){
            mp[t]++;
        }
        int res = 0;
        for(auto m:mp){
            if(m.second == 1){
                return -1;
            }
            res+=tb[m.second];
        }
        return res;
    }
    
    
};
int main(){
    vector<int> tasks = {2,2,3};
    Solution sol;
    int ans = sol.minimumRounds(tasks);
}