#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sumR = 0;
        int sumL = 0;
        for(auto n:nums){
            sumR+=n;
        }
        for(int i = 0;i<nums.size();i++){
            sumR -=nums[i];
            if(sumR == sumL){
                return i;
            }
            sumL+=nums[i];
        }
        return -1;
    }
};