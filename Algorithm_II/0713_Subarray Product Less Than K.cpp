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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<2){
            return 0;
        }
        int count = 0;
        int left = 0;
        int right = 0;
        int sum = 1;
        for(;right<nums.size();right++){
            sum *=nums[right];
            if(sum<k){
                count+=(right-left+1);
            }
            else{
                while (left<=right && sum>=k)
                {
                    sum/=nums[left];
                    left++;
                }
                if(left<=right){
                    count+=(right-left+1);
                }
            }
        }
        
        return count;
        
    }
};
int main(){
    vector<int> nums = {10,5,2,6,1,5};
    Solution sol;
    int ans = sol.numSubarrayProductLessThanK(nums,100);
}