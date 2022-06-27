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
class Solution
{
public:
    string discountPrices(string sentence, int discount)
    {
        string res = "";
        int idx = 0;
        while (idx < sentence.size())
        {
            if (sentence[idx] == '$' && idx<sentence.size() -1 )
            {
                int jdx = idx + 1;
                string org = "$";
                bool get = false;
                long _num = 0;
                while (jdx < sentence.size())
                {
                    org += sentence[jdx];
                    if (sentence[jdx] - '0' < 10 && sentence[jdx] - '0' >= 0)
                    {
                        get = true;
                        _num *= 10;
                        _num += (sentence[jdx] - '0');
                        if(jdx<sentence.size()-1)
                        {
                            jdx++;
                            continue;
                        }
                        
                    }
                    if (sentence[jdx] == ' ' || (jdx == sentence.size() - 1) && sentence[jdx] - '0' < 10 && sentence[jdx] - '0' >= 0)
                    {
                        res += '$';
                        if(get){
                            res += calculator(_num, discount);
                        }
                         
                        if (jdx != sentence.size() - 1)
                        {
                            res += ' ';
                        }
                        break;
                    }
                    else
                    {
                        res += org;
                        break;
                    }
                    
                }
                idx = jdx;
            }
            else
            {
                while (idx < sentence.size() && sentence[idx] != ' ')
                {
                    res += sentence[idx];
                    idx++;
                }
                if (idx < sentence.size() && sentence[idx] == ' ')
                {
                    res += sentence[idx];
                }
            }

            idx++;
        }
        return res;
    }
    string calculator(long target, int discount)
    {
        target *= 100;
        target -= (target / 100 * discount);
        string res = "";
        long _t = target;
        while (target > 0)
        {
            char tmp = '0' + (target % 10);
            target /= 10;
            res = tmp + res;
        }
        if (_t == 0){
            return "0.00";
        }
        if (_t < 10)
        {
            return "0.0" + res;
        }
        if (_t < 100)
        {
            res = "0." + res;
        }
        else
        {
            res.insert(res.end() - 2, '.');
        }
        return res;
    }
};
int main()
{
    Solution sol;
    string ans = sol.discountPrices("$1", 99);
}
// Constraints:

// 1 <= sentence.length <= 10^5
// sentence consists of lowercase English letters, digits, ' ', and '$'.
// sentence does not have leading or trailing spaces.
// All words in sentence are separated by a single space.
// All prices will be positive integers without leading zeros.
// All prices will have at most 10 digits.
// 0 <= discount <= 100