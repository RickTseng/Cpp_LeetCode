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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i+1<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start = i+1,end = nums.size()-1;
            while (start<end)
            {
                if(nums[start]+nums[end]== 0 - nums[i]){
                    res.push_back({nums[i],nums[start],nums[end]});
                    while(start<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    start++;
                    end--;
                }
                else if(nums[start]+nums[end]<0 - nums[i]){
                    start++;
                }
                else{
                    end--;
                }
            }
            
        }
        return res;
    }
};