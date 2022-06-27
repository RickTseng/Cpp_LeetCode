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

// Runtime: 4 ms, faster than 81.49% of C++ online submissions for Greatest English Letter in Upper and Lower Case.
// Memory Usage: 6.5 MB, less than 91.34% of C++ online submissions for Greatest English Letter in Upper and Lower Case.

class Solution {
public:
    string greatestLetter(string s) {
        string res = "";
        vector<int> loC(26,0),upC(26,0);
        for(auto c:s){
            if(c>='A'&& c<='Z')
            {
                upC[c-'A']++;
            }
            if(c>='a'&& c<='z')
            {
                loC[c-'a']++;
            }
        }
        for(int i = 25;i>=0;--i){
            if(loC[i]>0 && upC[i]>0){
                res = 'A'+i;
                break;
            }
        }
        return res;
    }
};