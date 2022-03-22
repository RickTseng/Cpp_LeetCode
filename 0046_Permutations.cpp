#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        ans = {{nums[0]}};
        creatOrder(nums.size(),nums);
        return ans;
    }
    void creatOrder(int n , vector<int> nums)
    {
        int i =1;
        //vector<vector<int>> tmp0 = {{0}};
        while (i<n)
        {
            vector<vector<int>> tmp;
            for(int idx = 0;idx<ans.size();idx++){
                
                for(int jdx = 0;jdx<=ans[idx].size();jdx++){
                    
                    vector<int> tmp00 = ans[idx];
                    tmp00.insert(tmp00.begin()+jdx,nums[i]);
                    tmp.push_back(tmp00);
                }
            }
            ans = tmp;
            i++;
        }
        
    }
};
int main(){
    Solution sol;
    vector<int> nums = {10,20,30,40};
    vector<vector<int>> ans = sol.permute(nums);
}
/**
 * @brief Runtime: 15 ms, faster than 5.70% of C++ online submissions for Permutations.
 * Memory Usage: 8.6 MB, less than 12.40% of C++ online submissions for Permutations.
 * 
 */