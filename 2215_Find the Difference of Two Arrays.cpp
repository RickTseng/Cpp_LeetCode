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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res0,res1;
        vector<int> db1(2001,0),db2(2001,0);
        for(auto n:nums1){
            db1[n+1000]++;
        }
        for(auto n:nums2){
            db2[n+1000]++;
        }
        for(int i = 0;i<db1.size();i++){
            if(db1[i]!=0 && db2[i]==0){
                res0.push_back(i-1000);
            }
            if(db1[i]==0 && db2[i]!=0){
                res1.push_back(i-1000);
            }
        }
        return {res0,res1};
    }
};