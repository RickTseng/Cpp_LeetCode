#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
class Solution{
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int count = 0;
            for(int i =nums.size()-1;i>=0;i--){
                int left = 0;
                int right = i-1;
                int target = nums[i];
                while (left<right)
                {
                    int lr_sum = nums[left]+nums[right];
                    if(lr_sum==target){
                        count++;
                        if(count==k){
                            return true;
                        }
                        left++;
                        right--;
                    }
                    else if (lr_sum>target){
                        right--;
                    }
                    else if (lr_sum<target){
                        left++;
                    }
                }
                
            } 
            
            return false;
        }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,7,8,9,4,1,1,1,5,4,2,3};
    bool ans = sol.canPartitionKSubsets(nums,7);
}

//Given an integer array nums and an integer k,
//return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

/********************************************************************/
/*       1 <= k <= nums.length <= 16                                */
/*       1 <= nums[i] <= 10^4                                       */
/*       The frequency of each element is in the range [1, 4].      */
/********************************************************************/