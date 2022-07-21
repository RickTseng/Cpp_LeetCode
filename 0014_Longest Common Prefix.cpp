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

// Runtime: 7 ms, faster than 54.44% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.3 MB, less than 51.49% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string res = "";
        for(int idx = 0;idx<strs[0].size();++idx){
            char target = strs[0][idx];
            for(int jdx = 1;jdx<strs.size();++jdx){
                if(strs[jdx][idx]!=target)
                {
                    return res;
                }           
            }
            res+=target;
        }
        return res;
    }
};