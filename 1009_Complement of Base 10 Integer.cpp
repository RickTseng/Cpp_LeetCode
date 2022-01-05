#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) 
    {
        vector<int> mp(31,1);
        vector<bool> tp(31,false);
        for(int i = 1;i<mp.size();i++){
            mp[i] = mp[i-1]*2;
        }
        int i = 30;
        int p = -1;
        while (i>=0)
        {
            if(n>=mp[i]){
                tp[i] = true;
                n-=mp[i];
                p = max(p,i);
            }
            i--;
        }
        int res = 0;
        for(int i = 0;i<=p;i++){
            if(!tp[i]){
                res+=mp[i];
            }
        }
        return 0;
    }
};
int main(){
    Solution sol;
    int ans = sol.bitwiseComplement(9);
}
