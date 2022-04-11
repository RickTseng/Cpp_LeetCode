#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto n:nums){
            pq.push(n);
        }
        while (k>0)
        {
            int tmp = pq.top();
            pq.pop();
            tmp++;
            pq.push(tmp);
            k--;
        }
        int res = 1;
        int m = 1e9 + 7;
        while (!pq.empty())
        {
            res*=pq.top();
            res%=m;
            pq.pop();
        }
        return res % m;
    }
};
int main(){
    vector<int> nums = {0,4};
    Solution sol;
    int ans = sol.maximumProduct(nums,5);
}