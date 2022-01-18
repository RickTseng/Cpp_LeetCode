#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int count = 0;
        int _max = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(i+1==k){
                count+=nums[i];
                _max = count;
                continue;
            }
            if(i+1>k){
                count = (count-nums[i-k]+nums[i]);
                _max = max(_max,count);
            }
            else{
                count+=nums[i];
            }
            
        }
        return (double)_max/k;
    }
};
int main(){
    vector<int> nums = {4,2,1,3,3};
    Solution sol;
    double ans = sol.findMaxAverage(nums,2);
}