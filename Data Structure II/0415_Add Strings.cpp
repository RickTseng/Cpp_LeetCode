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
    string addStrings(string num1, string num2)
    {
        int ad = 0,len1 = num1.size(),len2 = num2.size();
        string res = "";
        int idx = 1;
        while (len1 - idx >= 0 || len2 - idx >= 0)
        {
            int n1 = 0, n2 = 0;
            if (len1- idx >= 0)
            {
                n1 = num1[num1.size() - idx] - '0';
            }
            if (len2 - idx >= 0)
            {
                n2 = num2[num2.size() - idx] - '0';
            }
            int sum = n1 + n2 + ad;
            ad = sum / 10;
            char tmp = (sum % 10) + '0';
            res = tmp + res;
            idx++;
        }
        if (ad == 1)
        {
            res = '1' + res;
        }
        string res1 = "";
        return res;
    }
};
int main()
{
    Solution sol;
    string ans = sol.addStrings("45678944", "7755511");
}