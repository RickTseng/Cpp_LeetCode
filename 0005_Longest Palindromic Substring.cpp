#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int _max = 0;
        int leftPoint = 0;
        int rightPoint = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int left = -1;
            int right = 1;
            char t = s[i];
            while (i + right < s.size())
            {
                if (s[i + right] == t)
                {
                    if (right > _max)
                    {
                        leftPoint = i ;
                        rightPoint = i + right;
                        _max = right;
                    }
                    right++;
                }
                else
                {
                    break;
                }
            }
            while(i + left > -1 && i + right < s.size())
            {
                if (i + left > -1 && s[i + right] == s[i + left])
                {
                    if (right - left > _max)
                    {
                        leftPoint = i + left;
                        rightPoint = i + right;
                        _max = right - left;
                    }
                    right++;
                    left--;
                }
                else
                {
                    break;
                }
            }
        }
        string res = "";
        for(int i = leftPoint;i<=rightPoint;i++){
            res+=s[i];
        }
        return res;
    }
};
int main()
{
    Solution sol;
    string test = "xaabacxcabaaxcabaax";//"xaabacxcabaax"
    string test1 ="babad";
    for(int i = 0;i<100;i++){
        //test+='a';
    }
    string ans = sol.longestPalindrome(test1);
}

/*
    Input: s = "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.


    1 <= s.length <= 1000
    s consist of only digits and English letters.

    Runtime: 15 ms, faster than 90.15% of C++ online submissions for Longest Palindromic Substring.
    Memory Usage: 7.3 MB, less than 74.92% of C++ online submissions for Longest Palindromic Substring.



*/