#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int _max = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            for (int j = i + 1; j < colors.size(); j++)
            {
                if (colors[i] != colors[j])
                {
                    _max = max(_max, abs(i - j));
                }
            }
        }
        return _max;
    }
};
int main()
{
    Solution sol;
    vector<int> colors(100,1);
    colors[99] = 2;
    int ans = sol.maxDistance(colors);
}
/*
Input: colors = [1,1,1,6,1,1,1]
Output: 3

Input: colors = [1,8,3,8,3]
Output: 4

Input: colors = [0,1]
Output: 1

Constraints:

n == colors.length
2 <= n <= 100
0 <= colors[i] <= 100
Test data are generated such that at least two houses have different colors.

Runtime: 4 ms, faster than 72.73% of C++ online submissions for Two Furthest Houses With Different Colors.
Memory Usage: 8.9 MB, less than 54.55% of C++ online submissions for Two Furthest Houses With Different Colors.

*/