#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    int countVowelSubstrings(string word)
    {
        map<char, int> sap = {
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1}};
        map<char, int> vowel;
        int count = 0;
        for (int nb = 5; nb <= word.size(); nb++)
        {
            for (int i = 0; nb + i <= word.size(); i++)
            {
                vowel = sap;
                string tmp = "";
                for (int j = i; j < nb + i && j < word.size(); j++)
                {
                    if (sap.find(word[j]) == sap.end())
                    {
                        vowel = sap;
                        break;
                    }
                    if (vowel.find(word[j]) != vowel.end())
                    {
                        vowel.erase(word[j]);
                    }
                    tmp += word[j];
                }
                if (vowel.empty())
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    int ans = sol.countVowelSubstrings("cuaieuouac");
}
/*

Input: word = "cuaieuouac"
Output: 7

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.

Runtime: 460 ms, faster than 15.22% of C++ online submissions for Count Vowel Substrings of a String.
Memory Usage: 88 MB, less than 11.95% of C++ online submissions for Count Vowel Substrings of a String.


*/