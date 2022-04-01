#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> doubTable;
    vector<bool> path;
    bool isHappy(int n)
    {
        for (int i = 0; i < 10; i++)
        {
            doubTable.push_back(i * i);
        }
        path.resize(811);
        bool ans = false;
        jdg(n,ans);
        return ans;
    }
    void jdg(long long n,bool &ans)
    {
        long long sum = 0;
        while (n > 0)
        {
            sum += doubTable[n % 10];
            n /= 10;
        }
        if (!path[sum])
        {
            path[sum] = true;
            jdg(sum ,ans);
        }
        else{
            ans = (sum == 1 ? true:false);
            return;
        }
        
    }
};
int main()
{
    Solution sol;
    bool ans = sol.isHappy(2);
}