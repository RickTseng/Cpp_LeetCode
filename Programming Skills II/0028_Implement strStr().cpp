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
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        if(needle.size()>haystack.size()){
            return -1;
        }
        int left = 0;
        while(left < haystack.size())
        {
            int _left = left;
            int right = 0;
            while(right<needle.size() && _left < haystack.size() && haystack[_left]==needle[right]){
                right++;
                _left++;
            }
            if(right>=needle.size()){
                return left;
            }
            left++;
        }
        return -1;
    }
};