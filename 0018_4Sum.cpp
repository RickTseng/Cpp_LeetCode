#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ress;

        for(int i = 0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                int left = j+1;
                int right = nums.size()-1;
                int tmp_target = target - nums[i] - nums[j];
                while (left<right)
                {
                    int lr_sum = nums[left]+nums[right];
                    if(lr_sum==tmp_target){
                        vector<int> res = {nums[i],nums[j],nums[left],nums[right]};
                        if(find(ress.begin(),ress.end(),res)==ress.end()){
                            ress.push_back(res);
                        }
                        left++;
                        right--;
                    }
                    else if (lr_sum>tmp_target){
                        right--;
                    }
                    else if (lr_sum<tmp_target){
                        left++;
                    }
                }
                
            }
        }
        return ress;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> res = sol.fourSum(nums,0);
    int x =0;
}
//Runtime: 288 ms, faster than 14.68% of C++ online submissions for 4Sum.
//Memory Usage: 48.8 MB, less than 11.92% of C++ online submissions for 4Sum.