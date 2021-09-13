#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for(int i = 1 ; i < nums.size() ; ++i){
            //caculate current sub-array's total sum and current value,than find the max value.
            currentSum = max(currentSum + nums[i], nums[i]);
            //Record the max sum.
            maxSum = max(currentSum, maxSum);
        }

        return maxSum;
    }
};
int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    //vector<int> nums(30000,1);
    Solution sol;
    int ans = sol.maxSubArray(nums);
    printf("%d\n",ans);
    //system("pause");
}