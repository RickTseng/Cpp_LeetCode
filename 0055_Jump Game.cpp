#include<vector>
#include<stdio.h>
using namespace std;
bool canJump(vector<int>& nums) {
    int len = nums.size();
    if(len==0){
        return 0;
    }
    int _max = 0;
    for(int i =0;i<nums.size();i++){
        if(i>_max){
            return false;
        }
        if(_max>len){
            return true;
        }
        _max = max(_max,nums[i]+i);
    }
    return true;
}

int main(){
    vector<int> nums = {2,5,0,0};
    bool x = canJump(nums);
}