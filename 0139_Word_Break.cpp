#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <unordered_map>
using namespace std;
class Solution_ORG {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int index = 0;
        string tmp;
        vector<string> exitsWord;
        while (exitsWord.size()!= wordDict.size() && index<s.size())
        {
            tmp+=s[index];
            if(find(wordDict.begin(),wordDict.end(),tmp)!=wordDict.end() 
            && find(exitsWord.begin(),exitsWord.end(),tmp)==exitsWord.end()){
                exitsWord.push_back(tmp);
                tmp = "";
            }
            index++;
        }
        if(exitsWord.size()== wordDict.size()){
            return true;
        }
        else{
            return false;
        }
        
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto size = s.size();
        unordered_map<char, vector<string>> dict;
        for(auto& word: wordDict) {
            dict[word[0]].emplace_back(word);
        }
        
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        
        for(int i = 0; i <= size; ++i) {
            for(auto& element: dict[s[i]]) {
                auto e_size = element.size();
                if(dp[i] && element == s.substr(i, e_size)) 
                    dp[i + e_size] = true;
            }
        }
    
        return dp[size];
    }
};


int main(){
    Solution sol;
    vector<string> wordDict = {"cats", "dog", "cat","and"};
    bool ans = sol.wordBreak("catsandog",wordDict);
}

/***********************************************************/
/* 1 <= s.length <= 300
/* 1 <= wordDict.length <= 1000
/* 1 <= wordDict[i].length <= 20
/* s and wordDict[i] consist of only lowercase English letters.
/* All the strings of wordDict are unique.                 */