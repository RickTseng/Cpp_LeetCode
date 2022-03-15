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
    bool isValid(string s)
    {
        stack<char> st;

        for (auto ch : s)
        {
            if (st.empty())
            {
                st.push(ch);
                continue;
            }

            if (judgeChar(st.top(), ch))
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        return st.empty();
    }
    bool isValid_org(string s)
    {
        if (s.size() % 2 == 1)
        {
            return false;
        }
        while (!s.empty())
        {
            string sTmp = "";
            for (int i = 1; i < s.size(); i++)
            {
                if (judgeChar(s[i - 1], s[i]))
                {
                    i += 1;
                    for (; i < s.size(); i++)
                    {
                        sTmp += s[i];
                    }
                    break;
                }
                sTmp += s[i - 1];
            }
            if (sTmp.size() % 2 == 1)
            {
                return false;
            }
            s = sTmp;
        }

        return true;
    }
    bool judgeChar(char a, char b)
    {
        if (a == '(' && b == ')')
        {
            return true;
        }
        if (a == '[' && b == ']')
        {
            return true;
        }
        if (a == '{' && b == '}')
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    bool ans = sol.isValid("([]){}");
}