#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    /*
    
    Runtime: 4 ms, faster than 89.82% of C++ online submissions for Intersection of Two Arrays.
    Memory Usage: 10.2 MB, less than 72.12% of C++ online submissions for Intersection of Two Arrays.
    
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<vector<bool>> dp(2,vector<bool>(10001,false));
        int _max = -1;
        for(auto n:nums1){
            dp[0][n] = true;
            _max = max(_max,n);
        }
        for(auto n:nums2){
            dp[1][n] = true;
            _max = max(_max,n);
        }
        for(int i = 0;i<=_max;i++){
            if(dp[0][i] && dp[1][i]){
                res.push_back(i);
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution sol;
    vector<int> res = sol.intersection(nums1,nums2);
}