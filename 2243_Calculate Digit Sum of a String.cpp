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
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string tmp = "";
            int sum = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (i != 0 && i % k == 0)
                {
                    string tmp1 = "";
                    while (sum > 0)
                    {
                        char c = sum % 10 + '0';
                        sum /= 10;
                        tmp1 = c + tmp1;
                    }
                    if (tmp1 == "")
                    {
                        tmp += '0';
                    }
                    else
                    {
                        tmp += tmp1;
                    }
                }
                sum += s[i] - '0';
            }
            string tmp1 = "";
            while (sum > 0)
            {
                char c = sum % 10 + '0';
                sum /= 10;
                tmp1 = c + tmp1;
            }
            if (tmp1 == "")
            {
                tmp += '0';
            }
            else
            {
                tmp += tmp1;
            }
            s = tmp;
        }
        return s;
    }
};
int main()
{
    Solution sol;
    string ans = sol.digitSum("00000000", 3);
}