#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        vector<int> idxRC(1e6+1,-1);
        for(int idx = 0;idx<nums.size();idx++)
        {
            idxRC[nums[idx]] = idx;
        }
        for(int idx = 0;idx<operations.size();idx++)
        {
            nums[idxRC[operations[idx][0]]] = operations[idx][1];
            idxRC[operations[idx][1]] = idxRC[operations[idx][0]];
            idxRC[operations[idx][0]] = -1;          
        }
        return nums;
    }
};
// Constraints:

// n == nums.length
// m == operations.length
// 1 <= n, m <= 10^5
// All the values of nums are distinct.
// operations[i].length == 2
// 1 <= nums[i], operations[i][0], operations[i][1] <= 10^6
// operations[i][0] will exist in nums when applying the ith operation.
// operations[i][1] will not exist in nums when applying the ith operation.