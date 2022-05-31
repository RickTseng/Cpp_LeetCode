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
    int _rearrangeCharacters(string s, string target) 
    {
        string tmp = target;
        int count = 0;
        for(auto c:s)
        {
            int idx = 0;
            while (idx<tmp.size())
            {
                if(c == tmp[idx])
                {
                    tmp.erase(tmp.begin()+idx);
                    break;
                }
                else
                {
                    idx++;
                }
                
            }
            if(tmp.empty())
            {
                count++;
                tmp = target;
            }
            
        }
        return count;
    }
    int rearrangeCharacters(string s, string target)
    {
        vector<int> tb(26,0),sb(26,0);
        int res = 101;
        for(auto c:target)
        {
            tb[c-'a']++;
        }
        for(auto c:s){
            sb[c-'a']++;
        }
        for(int i = 0;i<26;i++)
        {
            if(tb[i]!=0)
            {
                res = min(res,sb[i]/tb[i]);
            }
        }
        return res;
    } 
};
int main(){
    Solution sol;
    int ans = sol.rearrangeCharacters("lrnvlcqukanpdnluowenfxquitzryponxsikhciohyostvmkapkfpglzikitwiraqgchxnpryhwpuwpozacjhmwhjvslprqlnxrk","woijih");
}