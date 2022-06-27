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
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        if(rowIndex==1){
            return {1,1};
        }
        vector<int> res(2,1);
        rowIndex-=1;
        while (rowIndex>0)
        {
            vector<int> tmp(res.size()+1,1);
            
            for(int i = 1;i<tmp.size() - 1;i++){
                tmp[i] = res[i-1] + res[i]; 
            }
            res = tmp;
            rowIndex--;
        }
        return res;
    }
};