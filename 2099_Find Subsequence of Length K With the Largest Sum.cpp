#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if(nums.size()==k){
            return nums;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        vector<bool> vb(nums.size(),false);
        for(int i = 0;i<nums.size();i++){
            pq.emplace(nums[i],i);
        }
        for(int i = 0;i<k;i++){
            vb[pq.top().second] = true;
            pq.pop();
        }
        for(int i = 0;i<nums.size();i++){
            if(vb[i]){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
int main(){

}
/*

Runtime: 8 ms, faster than 73.16% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.
Memory Usage: 9.6 MB, less than 59.17% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].

Constraints:

1 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5
1 <= k <= nums.length

*/