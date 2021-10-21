#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char,vector<int>> ABCmap;
        for(int i =0;i<t.size();i++){
            ABCmap[t[i]].push_back(i);
        }
        int index = -1;
        int count = 0;
        for(auto c:s){
            if(ABCmap.find(c)==ABCmap.end()){
                return false;
            }
            for(auto c_index:ABCmap[c]){
                if(c_index>index){
                    index = c_index;
                    count++;
                    break;
                }
            }
        }
        if(count==s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Solution sol;
    bool ans = sol.isSubsequence("axc","ahbgdc");
    printf("0000");
}
/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 10^9, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

Runtime: 3 ms, faster than 34.84% of C++ online submissions for Is Subsequence.
Memory Usage: 6.8 MB, less than 21.00% of C++ online submissions for Is Subsequence.

*/