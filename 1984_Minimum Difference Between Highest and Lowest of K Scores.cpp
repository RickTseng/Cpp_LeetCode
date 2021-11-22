#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int _min = 100001;
        for(int i = 0;i+k-1<nums.size() ;i++){
            _min = min(_min,abs(nums[i]-nums[i+k-1]));
        }
        return _min;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {9,4,1,7};
    int ans = sol.minimumDifference(nums,3);
}
/*
Constraints:

1 <= k <= nums.length <= 1000
0 <= nums[i] <= 10^5
*/