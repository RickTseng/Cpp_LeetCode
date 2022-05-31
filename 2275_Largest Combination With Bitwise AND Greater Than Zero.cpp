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
    int largestCombination(vector<int>& candidates) 
    {
        vector<int>tb(32,0);
        for(auto n:candidates){
            int idx = 0;
            while (n>0)
            {
                tb[idx]+=n%2;
                n/=2;
                idx++;
            }
        }
        return *max_element(tb.begin(),tb.end());
    }
};