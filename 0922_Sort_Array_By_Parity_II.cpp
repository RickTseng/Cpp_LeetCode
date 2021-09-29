#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution{
    //2 <= nums.length <= 2 * 10^4
    //nums.length is even.
    //Half of the integers in nums are even.
    //0 <= nums[i] <= 1000
    public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        int evenIndex = 0;
        int oddIndex = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]%2==0){
                res[evenIndex] = nums[i];
                evenIndex+=2;
            }
            else{
                res[oddIndex] = nums[i];
                oddIndex+=2;
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {4,2,5,7};
    for(int i = 0;i<10000;i++){
        nums.push_back(i+1);
    }
    vector<int> ans = sol.sortArrayByParityII(nums);
    printf("Finished\n");
}