#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;
class Solution
{
public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        
        int _max = 0;
        
        for (int i = 0; i < bombs.size(); i++)
        {           
            vector<bool> done(bombs.size(), false);
            int count = 1;
            done[i] = true;
            dfs(bombs,i,done,count,_max);
            if(_max == bombs.size()){
                break;
            }
        }
        return _max;
    }
    long long BTdistance(long long ax, long long ay, long long bx, long long by)
    {
        return (abs(ax - bx) * abs(ax - bx)) + (abs(ay - by) * abs(ay - by));
    }
    void dfs(vector<vector<int>> &bombs, int idx, vector<bool> &done,int &count,int &_max)
    {
        _max = max(_max,count);    
        long long r = bombs[idx][2];
        long long rangeB = r * r;
        for (int othb = 0; othb < bombs.size(); othb++)
        {
            
            if (!done[othb] && othb != idx && BTdistance(bombs[idx][0], bombs[idx][1], bombs[othb][0], bombs[othb][1]) <= rangeB)
            {
                count++;
                done[othb] = true;
                dfs(bombs, othb, done,count,_max);
            }
            
        }
    }
};
int main()
{
    vector<vector<int>> bombs = {{656,619,56},{189,402,178},{513,373,276},{900,510,14},{188,173,129},{512,178,251},{145,685,47},{504,355,500},{554,131,214},{596,1,98},{358,230,197},{88,758,155},{72,340,419},{818,708,222}};
    Solution sol;
    cout << sol.maximumDetonation(bombs) << endl;
}
/*
Input: bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}}
Output: 5
{{2,1,3},{6,1,4}}
Output: 2

{{656,619,56},{189,402,178},{513,373,276},{900,510,14},{188,173,129},{512,178,251},{145,685,47},{504,355,500},{554,131,214},{596,1,98},{358,230,197},{88,758,155},{72,340,419},{818,708,222}}
14
Constraints:

1 <= bombs.length <= 100
bombs[i].length == 3
1 <= xi, yi, ri <= 10^5

Runtime: 176 ms, faster than 45.10% of C++ online submissions for Detonate the Maximum Bombs.
Memory Usage: 12 MB, less than 97.06% of C++ online submissions for Detonate the Maximum Bombs.

*/