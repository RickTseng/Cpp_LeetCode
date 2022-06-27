#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int idx = 0,jdx = 0;
        int count  = 0;
        while(idx<g.size() && jdx < s.size()){
            while(jdx<s.size()){
                if(s[jdx]>=g[idx]){
                    count++;
                    jdx++;
                    break;
                }
                jdx++;
            }
            idx++;
        }
        return count;
    }
};