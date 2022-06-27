#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> res(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(int i = 0;i<spells.size();i++){
            int l = 0,r = potions.size();
            while(l<r){
                int mid = l + (r-l)/2;
                long long cmp = (long long)spells[i] * potions[mid];
                if(cmp>=success)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            res[i] = potions.size() - l;
            
            
            
        }
        return res;
    }
};