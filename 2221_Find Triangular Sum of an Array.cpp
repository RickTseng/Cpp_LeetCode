#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> tmp0 = nums;
        while(tmp0.size()>1){
            vector<int>tmp1;
            for(int i = 1;i<tmp0.size();i++){
                tmp1.push_back((tmp0[i]+tmp0[i-1])%10);
            }
            tmp0 = tmp1;
        }
        return tmp0[0];
    }
};