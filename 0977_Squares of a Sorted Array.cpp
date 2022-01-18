#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
bool cmp(int a,int b){
    return abs(a)<abs(b);
}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),cmp);
        for(int i = 0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        return nums;
    }
};
int main(){
    vector<int> nums ={0,1,2,3,4,5};
    Solution sol;
    vector<int> ans  = sol.sortedSquares(nums);
}