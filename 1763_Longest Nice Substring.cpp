#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        string sl = "";
        vector<bool> toV(s.size(), false);
        for (int i = 0; i < s.size(); i++)
        {
            if (toV[i])
            {
                continue;
            }
            int target = s[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (i != j && (s[j] - 32 == target || s[j] + 32 == target))
                {
                    toV[i] = true;
                    toV[j] = true;
                }
            }
        }
        return s;
    }
};
int main()
{
    Solution sol;
    string ans = sol.longestNiceSubstring("BebbabbbbBBBBjjJJJJeeb");
}