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
    string licenseKeyFormatting(string s, int k) {
        string _s = "";
        for(auto c:s){
            if(c!='-'){
                if(c>96 && c<123){
                    c-=32;
                }
                _s+=c;
            }
        }
        if(_s.size()<=k){
            return _s;
        }
        int idx = _s.size() - k;
        while (idx>0)
        {
            _s.insert(idx,1,'-');
            idx-=k;
        }
        return _s;
    }
};
int main(){
    Solution sol;
    string ans  = sol.licenseKeyFormatting("5F3Z-2e-9-w",4);
}