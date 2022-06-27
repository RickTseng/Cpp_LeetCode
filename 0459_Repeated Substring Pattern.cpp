#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() % 2 == 1)
        {
            return false;
        }
        string tmp0 = "";
        
        return true;
    }
    int findComplement(int num)
    {
        vector<int> tb;
        while(num>0){
            tb.push_back(num%2);
            num/=2;
        }
        long long p = 1;
        int res = 0;
        for(int i = 0;i<tb.size();i++){
            if(tb[i]==0){
                res += p;
            }
            p*=2;
        }
        return res;
    }
};
int main()
{
    Solution sol;
    int ans = sol.findComplement(10);
}