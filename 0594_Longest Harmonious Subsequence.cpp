#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int,int> mp;
        for(auto n:nums)
        {
            mp[n]++;
        }
        int _max = 0;
        auto t = mp.begin();
        auto it = ++mp.begin();
        for(;it!=mp.end();++it){
            if(it->first == t->first + 1){
                _max = max(_max,t->second + it->second);
            }
            t = it;
        }
        return _max;
    }
};
int main(){
    vector<int> nums = {1,3,2,2,5,2,3,7};
    Solution sol;
    int ans = sol.findLHS(nums);
}