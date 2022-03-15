#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        vector<int> pTable(26, 0), sTable(26, 0), res;
        if (p.size() > s.size())
        {
            return res;
        }
        for (auto c : p)
        {
            pTable[c - 'a']++;
        }
        int idx = 0;
        for (; idx < p.size(); idx++)
        {
            sTable[s[idx] - 'a']++;
        }
        if (judgeTable(pTable, sTable))
        {
            res.push_back(idx - p.size());
        }
        for (; idx < s.size(); idx++)
        {
            sTable[s[idx - p.size()] - 'a']--;
            sTable[s[idx] - 'a']++;
            if (judgeTable(pTable, sTable))
            {
                res.push_back(idx - (p.size() - 1));
            }
        }
        return res;
    }
    bool judgeTable(vector<int> pTable, vector<int> sTable)
    {
        for (int i = 0; i < 26; i++)
        {
            if (pTable[i] != sTable[i])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.findAnagrams("cbaebabacd", "abc");
}