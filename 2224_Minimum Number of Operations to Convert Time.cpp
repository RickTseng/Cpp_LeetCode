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
    int convertTime(string current, string correct)
    {
        int cur = (current[0] - '0') * 600 + (current[1] - '0') * 60 + (current[3] - '0') * 10 + (current[4] - '0');
        int cor = (correct[0] - '0') * 600 + (correct[1] - '0') * 60 + (correct[3] - '0') * 10 + (correct[4] - '0');
        int df = cor - cur;
        int count = 0;
        count += df / 60;
        df %= 60;
        count += df / 15;
        df %= 15;
        count += df / 5;
        count += df % 5;
        return count;
    }
};