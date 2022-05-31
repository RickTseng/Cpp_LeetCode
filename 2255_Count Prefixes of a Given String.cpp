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
    int countPrefixes(vector<string>& words, string s) 
    {
        int count = 0;
        for(auto word:words){
            for(int i = 0;i<s.size();i++)
            {
                if(word[i] != s[i]){
                    break;
                }
                if(i == word.size() - 1){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};