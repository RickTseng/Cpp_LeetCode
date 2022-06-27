#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        tmp.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
            tmp.push_back(tmp[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return tmp[right];
        }
        else{
            return tmp[right] - tmp[left - 1];
        }
    }
private:
    vector<int> tmp;
};