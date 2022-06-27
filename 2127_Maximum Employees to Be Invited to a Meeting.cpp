#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int _max = 0;
        for (int i = 0; i < favorite.size(); i++)
        {
            vector<int> bbb;
            set<int> sss;       
            bbb.push_back(i);
            sss.emplace(i);
            int curIdx = favorite[i];
            pair<set<int>::iterator,bool> ret;
            while (true)
            {
                
                ret = sss.insert(curIdx);
                if(!ret.second){
                    if(bbb[0]==curIdx||bbb[bbb.size()-2]==curIdx){
                        int s= bbb.size();
                        _max = max(_max,s);
                    }
                    break;
                }
                else{
                    bbb.push_back(curIdx);
                }
                curIdx = favorite[curIdx];
            }
        }
        return _max;
    }
    
};
int main()
{
    Solution sol;
    vector<int> favorite;
    for(int i = 0;i<100000;i++){
        favorite.push_back(i+1);
    }
    //vector<int> favorite = {1,0,0,2,1,4,7,8,9,6,7,10,8};
    //vector<int> favorite = {2,2,1,2};
    int ans = sol.maximumInvitations(favorite);
}
/*

70 / 98 test cases passed.

[1,0,0,2,1,4,7,8,9,6,7,10,8]
6
Constraints:

n == favorite.length
2 <= n <= 10^5
0 <= favorite[i] <= n - 1
favorite[i] != i

*/