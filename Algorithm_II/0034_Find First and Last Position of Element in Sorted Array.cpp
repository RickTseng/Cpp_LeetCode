#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0,end = nums.size()-1;
        vector<int> res(2,-1);
        while (start<=end)
        {
            if(nums[start]==target && nums[end]==target){
                res[0] = start;
                res[1] = end;
                break;
            }
            if(nums[start]!=target){
                start++;
            }
            if(nums[end]!=target){
                end--;
            }
            
        }
        return res;
    }
};