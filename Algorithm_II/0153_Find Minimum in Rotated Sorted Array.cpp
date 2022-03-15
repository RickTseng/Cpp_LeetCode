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
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        if (nums[r] >= nums[0])
            return nums[0];
        
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            if (nums[mid] < nums[mid-1])
                return nums[mid];
            
            if (nums[mid] > nums[0])
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
};