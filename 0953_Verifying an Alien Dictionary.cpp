#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};
int main(){
    vector<string> words = {"word","world","row"};
    Solution sol;
    bool ans = sol.isAlienSorted(words,"worldabcefghijkmnpqstuvxyz");
}