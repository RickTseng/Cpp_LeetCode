#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) 
    {
        int idx = 1;
        string res = "";
        int _max = -1;
        while(idx + 1 < num.size()){
            if(num[idx-1] == num[idx] && num[idx] == num[idx+1])
            {
                if(num[idx]-'0'>_max)
                {
                    _max = num[idx]-'0';
                    res = "";
                    res += num[idx];
                    res += num[idx];
                    res += num[idx];
                }
            }
            idx++;
        }
        return res; 
    }
};