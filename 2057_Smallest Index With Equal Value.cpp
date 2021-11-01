#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(i%10==nums[i]){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    vector<int> nums = {7,8,3,5,2,6,3,1,1,4,5,4,8,7,2,0,9,9,0,5,7,1,6};
    Solution sol;
    int ans = sol.smallestEqual(nums);
    printf("%d\n",ans);
}
/*
[7,8,3,5,2,6,3,1,1,4,5,4,8,7,2,0,9,9,0,5,7,1,6]
21


Input: nums = [4,3,2,1]
Output: 2
Explanation: 
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 is the only index which has i mod 10 == nums[i].


1 <= nums.length <= 100
0 <= nums[i] <= 9


*/