#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution{
    public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size(),0);
        for(int i =0;i<nums.size();i++){
            if(i<nums.size()/2){
                res[i*2] = nums[i];       //even index
            }
            else{
                res[2*(i-n)+1] = nums[i]; //odd index
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums = {2,5,1,3,4,7};
    Solution sol;
    vector<int> ans = sol.shuffle(nums,3);
    printf("finished");
}
//Accept 8ms
