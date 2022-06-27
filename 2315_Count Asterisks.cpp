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

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Asterisks.
// Memory Usage: 6.4 MB, less than 77.78% of C++ online submissions for Count Asterisks.


class Solution {
public:
    int countAsterisks(string s) 
    {
        int len = s.size();
        int countStar = 0,count = 0;
        for(int idx = 0;idx<len;++idx){
            if(s[idx]=='|')
            {
                count++;
            }
            else
            {
                if(count%2==0 && s[idx]=='*')
                {
                    countStar++;
                }
            }
        }
        return countStar;
    }
};