#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    bool checkString(string s)
    {
        int bMin = s.size();
        int aMax = -1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'b')
            {
                bMin = min(bMin, i);
            }
            if (s[i] == 'a')
            {
                aMax = max(aMax, i);
            }
        }
        if (bMin > aMax)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};