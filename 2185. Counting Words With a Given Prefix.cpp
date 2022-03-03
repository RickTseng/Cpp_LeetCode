#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (auto s : words)
        {
            if (s.size() < pref.size())
            {
                continue;
            }
            if (s.size() == pref.size() && s == pref)
            {
                count++;
                continue;
            }
            string tmp = "";
            for (int i = 0; i < pref.size(); i++)
            {
                tmp += s[i];
            }
            if (tmp == pref)
            {
                count++;
            }
        }

        return count;
    }
};