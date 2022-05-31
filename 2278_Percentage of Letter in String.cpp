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
    int percentageLetter(string s, char letter) 
    {
        vector<int> tb(26,0);
        for(auto c:s){
            tb[c-'a']++;
        }
        int res = 0;
        res = ((double)tb[letter - 'a'] / (double)s.size()) * 100;
        return res;
    }
};
int main(){
    Solution sol;
    int ans = sol.percentageLetter("foobar",'o');
}