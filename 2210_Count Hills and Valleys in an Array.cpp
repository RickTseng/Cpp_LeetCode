#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>nums[i-1]){
                while (i+1<nums.size())
                {
                    if(nums[i+1]>=nums[i]){
                        i++;
                    }
                    else{
                        count++;
                        break;
                    }
                }            
            }
            if(nums[i]<nums[i-1]){
                while (i+1<nums.size())
                {
                    if(nums[i+1]<=nums[i]){
                        i++;
                    }
                    else{
                        count++;
                        break;
                    }
                } 
            }
        }
        return count;
    }
};
int main(){
    vector<int> nums = {6,6,5,5,4,9};
    Solution sol;
    int ans = sol.countHillValley(nums);
}