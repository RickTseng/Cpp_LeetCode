#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

// Runtime: 2818 ms, faster than 11.11% of C++ online submissions for Query Kth Smallest Trimmed Number.
// Memory Usage: 421.3 MB, less than 11.11% of C++ online submissions for Query Kth Smallest Trimmed Number.

class Solution {
    struct Cmp {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        }
    }cmp;
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        vector<int> res(queries.size(),-1);
        for(int i = 0;i<queries.size();++i)
        {
            int smidx = queries[i][0];
            int digis = queries[i][1];
            vector<pair<string,int>> vt;
            //set<pair<string,int>> st;
            for(int idx = 0;idx<nums.size();++idx)
            {
                string tmpStr(end(nums[idx])-digis,end(nums[idx]));
                //st.insert({tmpStr,idx});
                vt.push_back({tmpStr,idx});
                
            }
            sort(begin(vt),end(vt),cmp);
            //auto it = st.begin();
            //it+=smidx;
            res[i] = vt[smidx-1].second;
        }
        return res;
    }
};
int main(){

    vector<string> nums = {"459","222","401","125","101"};
    vector<vector<int>> queries = {{1,2}};
    Solution sol;
    auto ans = sol.smallestTrimmedNumbers(nums,queries);

}