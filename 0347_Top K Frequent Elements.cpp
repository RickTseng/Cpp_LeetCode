#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> db;
        
        priority_queue<pair<int,int>> _order;
        for(auto n:nums){
            if(db.find(n)==db.end()){
                db[n]=1;
            }
            else{
                db[n]++;
            }
        }
        for(auto d:db){
            _order.push({d.second ,d.first});
        }
        vector<int> res;
        for(int i = 0;i<k;i++){
            res.push_back(_order.top().second);
            _order.pop();
        }
        return res;
    }
};
int main(){
    vector<int> nums = {4,1,-1,2,-1,2,3};
    Solution sol;
    vector<int> ans = sol.topKFrequent(nums,2);
}
/*
Runtime: 16 ms, faster than 74.34% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.9 MB, less than 22.54% of C++ online submissions for Top K Frequent Elements.



Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

[4,1,-1,2,-1,2,3]
2
[-1,2]


*/