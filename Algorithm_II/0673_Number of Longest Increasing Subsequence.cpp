#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // not finished
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(),{1,1});
        int _maxN = nums[0];
        int _maxL = 1;        
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>_maxN){
                dp[i].first = _maxL+1;
                dp[i].second = nums[i];
                _maxN = nums[i];
                _maxL++;
            }
            else{
                int j = i;
                while (j>=0)
                {
                    if(nums[j]<nums[i]){
                        dp[i].first = dp[j].first;
                        dp[i].first ++;
                        dp[i].second = _maxN;
                        break;
                    }
                    j--;
                }
                
            }
        }




        return 0;
    }
    
};
int main(){
    vector<int> nums = {1,5,7,4,2,6,8,3,1,9};
    //vector<int> nums;
    for(int i = 1;i<=2000;i++){
        //nums.push_back(i);
    }
    Solution sol;
    int ans = sol.findNumberOfLIS(nums);
}