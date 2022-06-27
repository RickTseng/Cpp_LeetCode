#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string res = "";
        if (num < 0)
        {
            num = abs(num);
            while (num > 0)
            {
                char tmp = num % 7 + '0';
                res = tmp + res;
                num /= 7;
            }
            res = '-' + res;
        }
        else
        {
            while (num > 0)
            {
                char tmp = num % 7 + '0';
                res = tmp + res;
                num /= 7;
            }
        }

        return res;
    }
};