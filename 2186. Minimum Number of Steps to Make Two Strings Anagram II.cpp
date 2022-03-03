#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sLog(26,0),tLog(26,0);
        for(auto c:s){
            sLog[c-'a']++;
        }
        for(auto c:t){
            tLog[c-'a']++;
        }
        int count = 0;
        for(int i = 0;i<26;i++){
            count+=abs(sLog[i]-tLog[i]);
        }
        return count;
    }
};