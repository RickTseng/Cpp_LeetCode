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
    vector<int> partitionLabels(string s) {
        vector<int> tb(26,0),res;
        for(int i = 0;i<s.size();i++){
            tb[s[i]-'a'] = i;
        }
        int prev = -1;
        int maxIdx = 0;
        for(int i = 0;i<s.size();i++){
            maxIdx = max(maxIdx,tb[s[i]]);
            if(maxIdx = i){
                res.push_back(maxIdx - prev);
                prev = maxIdx;
            }
        }
        return res;
    }
};