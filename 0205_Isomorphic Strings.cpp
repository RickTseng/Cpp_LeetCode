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

// Runtime: 43 ms, faster than 5.12% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 9.3 MB, less than 5.15% of C++ online submissions for Isomorphic Strings.


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,vector<int>> sMap,tMap;
        unordered_map<char,bool> sBool,tBool;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0;i<s.size();++i){
            sMap[s[i]].push_back(i);
            sBool[s[i]] = false;
        }
        for(int i = 0;i<t.size();++i){
            tMap[t[i]].push_back(i);
            tBool[t[i]] = false;
        }
        for(int idx = 0;idx<s.size();++idx)
        {
            if(sMap[s[idx]].size()==tMap[t[idx]].size()){
                if(sBool[s[idx]] && tBool[t[idx]])
                {
                    continue;
                }
                int len = sMap[s[idx]].size();
                for(int jdx = 0;jdx<len;++jdx){
                    if(sMap[s[idx]][jdx]!=tMap[t[idx]][jdx]){
                        return false;
                    }
                }
                sBool[s[idx]] = true;
                tBool[t[idx]] = true;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    bool ans = sol.isIsomorphic("qwertyuiop[]asdfghjkl;'\\zxcvbnm,./","',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz");
}
// "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./"
// "',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz"