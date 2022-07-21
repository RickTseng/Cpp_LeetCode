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

// Constraints:

// 1 <= words.length <= 500
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]


// Runtime: 44 ms, faster than 5.56% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 14.8 MB, less than 6.42% of C++ online submissions for Top K Frequent Words.

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> mp;
        vector<map<string,int>>frq;
        for(auto str:words){
            mp[str]++;
            if(frq.size()<mp[str])
            {
                map<string,int> tmp;
                tmp[str] = mp[str];
                frq.push_back(tmp);
                
            }
            else{
                frq[mp[str] - 1][str] = mp[str];
            }
            if(mp[str]>1)
            {
                frq[mp[str]-2].erase(str);
            }
        }
        while (k>0)
        {
            if(frq.back().empty())
            {
                frq.pop_back();
            }
            if(!frq.back().empty())
            {
                res.push_back(frq.back().begin()->first);
                frq.back().erase(res.back());
                k--;
            }
        }
        return res;
    }
};
int main(){
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    Solution sol;
    vector<string> ans = sol.topKFrequent(words,4);
}