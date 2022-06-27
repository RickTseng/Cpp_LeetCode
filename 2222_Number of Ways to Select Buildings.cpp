#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    long long numberOfWays(string &s, char firstLast)
    {
        long long first = 0, second = 0, comb = 0, res = 0;
        for (char ch : s)
            if (ch == firstLast)
            {
                comb += first * second;
                res += comb;
                second = 0;
                ++first;
            }
            else
                ++second;
        return res;
    }
    long long numberOfWays(string s)
    {
        return numberOfWays(s, '0') + numberOfWays(s, '1');
    }
};