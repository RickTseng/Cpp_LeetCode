#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
// Constraints:

// 1 <= sub.length <= s.length <= 5000
// 0 <= mappings.length <= 1000
// mappings[i].length == 2
// oldi != newi
// s and sub consist of uppercase and lowercase English letters and digits.
// oldi and newi are either uppercase or lowercase English letters or digits.
class Solution
{
public:
    bool matchReplacement(string s, string sub, vector<vector<char>> &mappings)
    {
        map<char, priority_queue<int, vector<int>, greater<int>>> table;
        for (int i = 0; i < 26; i++)
        {
            table['a' + i] = {};
            table['A' + i] = {};
            if (i < 10)
            {
                table['0' + i] = {};
            }
        }
        string tmp = "";
        for (int i = 0; i < sub.size(); i++)
        {
            tmp += s[i];
            table[sub[i]].push(i);
        }
        for (int i = 0; i < mappings.size(); i++)
        {
            if (!table[mappings[i][0]].empty())
            {
                sub[table[mappings[i][0]].top()] = mappings[i][1];
                table[mappings[i][1]].push(table[mappings[i][0]].top());
                table[mappings[i][0]].pop();
            }
        }
        if (tmp == sub)
        {
            return true;
        }
        for (int i = tmp.size(); i < s.size(); i++)
        {
            tmp.erase(begin(tmp));
            tmp += s[i];
            if (tmp == sub)
            {
                return true;
            }
        }
        return false;
    }
};
//"fool3e7bar", sub = "leet", mappings = [["e","3"],["t","7"],["t","8"]]
int main()
{
    Solution sol;
    vector<vector<char>> mappings = {{'e', '3'}, {'t', '7'}, {'t', '8'}};
    bool ans = sol.matchReplacement("fool3e7bar", "leet", mappings);
}