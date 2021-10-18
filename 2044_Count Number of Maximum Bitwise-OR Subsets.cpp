#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(auto i:nums){
            target|=i;
        }
        int count = 0;
        int res = 0;
        
        dfs(nums,target,0,res,count);
        for(int i = 0;i<nums.size();i++){
            

        }
        return count;
    }
    void dfs(vector<int> nums,int target,int index,int res,int& count){
        if(res==target){
            count++;
        }
        if(index>=nums.size()){
            return;
        }
        for(;index<nums.size();index++){
            dfs(nums,target,index+1,res|nums[index],count);
        }
    }
};
int main(){
    Solution sol;
    vector<int> nums = {3,2,1,5,7,11,67,84,49,10,11,12,13,14,15,16};
    int ans = sol.countMaxOrSubsets(nums);
}
/*

Input: nums = [3,2,1,5]
Output: 6

1 <= nums.length <= 16
1 <= nums[i] <= 10^5

Runtime: 432 ms, faster than 23.08% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.
Memory Usage: 187.2 MB, less than 7.69% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.



*/