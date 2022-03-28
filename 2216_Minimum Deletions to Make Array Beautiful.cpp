#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int count = 0;
        int idx = 0;
        while (idx<nums.size())
        {
            while (idx+1<nums.size() && nums[idx]==nums[idx+1])
            {
                count++;
                idx++;
            }
            if(idx+1>=nums.size()){
                count++;
                break;
            }
            idx+=2;
            
        }
        return count;
    }
};
int main(){
    vector<int> nums = {3,4,9};
    Solution sol;
    int ans = sol.minDeletion(nums);
}