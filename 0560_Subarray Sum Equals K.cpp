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
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1){
            return nums[0] == k? 1:0;
        }
        int count = 0;
        if(nums[0]==k){
            count++;
        }
        for(int i = 1;i<nums.size();i++){
            nums[i] += nums[i-1];
            if(nums[i]==k){
                count++;
            }
            for(int j = 0;j<i;j++){
                if(nums[i]-nums[j] == k){
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    vector<int> nums = {-1,-1,1};
    Solution sol;
    int ans = sol.subarraySum(nums,0);
}