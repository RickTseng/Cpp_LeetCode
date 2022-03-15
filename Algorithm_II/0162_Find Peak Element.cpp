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
    int findPeakElement(vector<int>& nums) {
        int mid, left = 0, right = nums.size() - 1;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1])
            right = mid;
            else left = mid + 1;
        }
        return left;
    }
};