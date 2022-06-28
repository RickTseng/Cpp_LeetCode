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

// Ref Lee215's solution
// Runtime: 4 ms, faster than 97.04% of C++ online submissions for Longest Repeating Character Replacement.
// Memory Usage: 7.1 MB, less than 53.78% of C++ online submissions for Longest Repeating Character Replacement.

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int maxf = 0, i = 0, n = s.length();
        vector<int> count(26);
        for (int j = 0; j < n; ++j) {
            //找出目前字元(char)最大的出現頻率 即為maxf
            maxf = max(maxf, ++count[s[j] - 'A']);
            //如果window的長度大於window內的最大出現頻率char + 可修改字數(k)
            //window視窗左側右移1(i++) 當下char頻率(--);
            if (j - i + 1 > maxf + k)
                --count[s[i++] - 'A'];
        }
        //回傳window左側(i)至總長度之距離為最長字串(string)

        return n - i;
    }
};