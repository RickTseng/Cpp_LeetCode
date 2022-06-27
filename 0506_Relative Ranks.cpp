#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<string> order,res(score.size(),"");
        order.push_back("Gold Medal");
        order.push_back("Silver Medal");
        order.push_back("Bronze Medal");
        for(int i = 4;i<=score.size();i++){
            string tmp = "" ;
            int num = i;
            while (num>0)
            {
                char c = '0'+ (num % 10);
                tmp = c + tmp;
                num /= 10;
            }           
            order.push_back( tmp );
        }
        map<int,int,greater<int>> mp;
        for(int i = 0;i<score.size();i++){
            mp[score[i]] = i;
        }
        int idx = 0;
        for(auto it = mp.begin();it!=mp.end();++it,idx++){
            res[it->second] = order[idx];
        }
        return res;
    }
};
int main(){
    vector<int> score = {10,3,8,9,4};
    Solution sol;
    vector<string> ans = sol.findRelativeRanks(score);
}

/**
 * The 1st place athlete's rank is "Gold Medal".
 * The 2nd place athlete's rank is "Silver Medal".
 * The 3rd place athlete's rank is "Bronze Medal".
 * For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
 * 
 * */