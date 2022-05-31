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
    vector<string> removeAnagrams(vector<string>& words) 
    {

        int tIdx = 1;
        while (tIdx < words.size())
        {
            if (cmper(words[tIdx-1], words[tIdx]))
            {
                words.erase(words.begin() + tIdx);
            }
            else
            {
                tIdx++;
            }
        }
        return words;
    }
    bool cmper(string str_L,string str_R)
    {
        sort(str_L.begin(),str_L.end());
        sort(str_R.begin(),str_R.end());
        if(str_L == str_R)
        {
            return true;
        }
        return false;
    } 
};
int main(){
    vector<string> words = {"abba","baba","bbaa","cd","cd"};
    Solution sol;
    vector<string> ans = sol.removeAnagrams(words);
}