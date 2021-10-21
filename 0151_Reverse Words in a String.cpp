#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stack<string> tmp;
        string res = "";
        string s0;
        int index = 0;
        while (index<s.size())
        {
            while (s[index]==' ')
            {
                if(s0.size()!=0){
                    tmp.push(s0);
                }
                index++;
                s0.clear();
            }
            s0+=s[index];
            index++;
        }
        if(s0[0]!='\000'){
            tmp.push(s0);
        }
        while (!tmp.empty())
        {
            res+=tmp.top();
            tmp.pop();
            if(tmp.size()>0){
                res+=" ";
            }
        }
        
        return res;
    }
};
int main(){
    Solution sol;
    string ans = sol.reverseWords("  hello world  ");
    //string ans = sol.reverseWords("the sky is blue");
}

/*
    Input: s = "  hello world  "
    Output: "world hello"



    1 <= s.length <= 10^4
    s contains English letters (upper-case and lower-case), digits, and spaces ' '.
    There is at least one word in s.
    
    Runtime: 4 ms, faster than 84.03% of C++ online submissions for Reverse Words in a String.
    Memory Usage: 7.5 MB, less than 64.42% of C++ online submissions for Reverse Words in a String.

*/