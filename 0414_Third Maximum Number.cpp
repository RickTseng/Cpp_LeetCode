#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        set<int,greater<int>> tmp;
        for(auto n:nums){
            tmp.insert(n);
        }
        int _max = *tmp.begin();
        if(tmp.size()<3)
        {
            return _max;
        }
        

        tmp.erase(tmp.begin());
        tmp.erase(tmp.begin());
        return *tmp.begin();
        
    }
};
int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    int ans = sol.thirdMax(nums);
}