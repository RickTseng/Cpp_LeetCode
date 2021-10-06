#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;


class Solution_org{
public:
    int rob(vector<int>& nums) {
        int _max = 0;
        
        for(int i = 0;i<nums.size();i++){
            vector<int> sum(nums.size(),0);
            
            dfs(nums,sum,i,0,_max);
        }
        return _max;
    }
    void dfs(vector<int>& nums,vector<int>& sum ,int index, int count, int &_max){
        count+=nums[index];
        _max = max(_max,count);
        sum[index] = _max;
        int next = 2;
        while (index+next<nums.size())
        {
            
            dfs(nums,sum,index+next,count,_max);
            next++;
        }
        
    }
};
//Web solution
class Solution{
    public:
    int rob(vector<int>& nums) {
        int _max = 0;
        vector<int> res(nums.size(),-1);
        return dfs(nums,nums.size()-1,res);
    }
    int dfs(vector<int>& nums,int index,vector<int>& res){
        if(index < 0){
             return 0;
        }      
        if(res[index] >= 0){
            return res[index];
        }
        res[index]=max(dfs(nums,index-1,res),dfs(nums,index-2,res)+nums[index]);
        return res[index];
        
    }
    int rob_II(vector<int>& nums){
        if (nums.size() <= 1){
            return nums.empty()? 0 : nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        int _max = 0;
        for(int n = 0;n<nums.size();n++){
            if(n>0){
                nums.push_back(nums[0]);
                nums.erase(nums.begin(),++nums.begin());
            }
            
            vector<int> dp = {nums[0], max(nums[0], nums[1])};
            int defaultLen = nums.size();
            if(nums[0]+nums[2]>nums[1]){
                defaultLen -=1;
            }
            for (int i = 2; i < defaultLen; ++i) {
                dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
            }
            _max = max(_max,dp.back());
            //return dp.back();
        }
        return _max;
    }
};
int main(){
    Solution sol;

    //vector<int> nums = {7,4,5,1,3,0,1,2,1,5,4,8,4,5,1,2,3,4,8,7,2,7,9,3,1,1,2,1,5,1,5,6,4,8};
    //vector<int> nums(100,1);
    vector<int> nums = {0,0};
    int ans = sol.rob_II(nums);



    return 0;
}

//rob 1
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
//Memory Usage: 7.9 MB, less than 5.69% of C++ online submissions for House Robber.

//rob 2
//Runtime: 10 ms, faster than 6.42% of C++ online submissions for House Robber II.
//Memory Usage: 9.1 MB, less than 5.21% of C++ online submissions for House Robber II.