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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                i++;
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,1,2};
    vector<int> res = sol.findDuplicates(nums);
}
//[4,3,2,7,8,2,3,1]