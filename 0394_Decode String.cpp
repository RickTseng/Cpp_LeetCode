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

// Runtime: 4 ms, faster than 33.72% of C++ online submissions for Decode String.
// Memory Usage: 6.5 MB, less than 78.00% of C++ online submissions for Decode String.

class Solution
{
public:
    string decodeString(string s)
    {
        string res;
        int idx = 0;
        readDeep(s, idx);
        return s;
    }
    void readDeep(string &s, int idx)
    {
        while (idx < s.length())
        {
            int repeartCount = 0;
            while (s[idx] >= '0' && s[idx] <= '9')
            {
                repeartCount *= 10;
                repeartCount += (s[idx] - '0');
                s.erase(begin(s) + idx);
            }
            string rpStr = "";
            if (s[idx] == '[')
            {
                s.erase(begin(s) + idx);
                while (s[idx] != ']')
                {
                    if (s[idx] >= 'a' && s[idx] <= 'z')
                    {
                        rpStr += s[idx];
                        s.erase(begin(s) + idx);
                    }
                    if (s[idx] >= '0' && s[idx] <= '9')
                    {
                        readDeep(s, idx);
                    }
                }
                if (rpStr != "" && s[idx] == ']')
                {
                    s.erase(begin(s) + idx);
                    for (int jdx = 0; jdx < repeartCount; ++jdx)
                    {
                        s.insert(begin(s) + idx, begin(rpStr), end(rpStr));
                    }
                }
            }
            ++idx;
        }
    }
};
int main()
{
    Solution sol;
    string ans = sol.decodeString("3[a2[c]]");
}

// Constraints:
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// 1 <= s.length <= 30
// s consists of lowercase English letters, digits, and square brackets '[]'.
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].