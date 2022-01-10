#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int len = max(a.size(),b.size());
        while (a.size()<len)
        {
            a = '0'+a;
        }
        while (b.size()<len)
        {
            b = '0'+b;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vector<bool> ad(len + 1, false);
        string res;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                ad[i + 1] = true;
                if (ad[i])
                {
                    res += '1';
                }
                else
                {
                    res += '0';
                }
            }
            else
            {
                if(a[i]=='1'||b[i]=='1'){
                    if(ad[i]){
                        ad[i+1] = true;
                        res+='0';
                    }
                    else{
                        res+='1';
                    }
                }
                else{
                    if(ad[i]){
                        res+='1';
                    }
                    else{
                        res+='0';
                    }                
                }
            }
        }
        if(ad.back()){
            res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    Solution sol;
    string ans = sol.addBinary("1", "11");
}