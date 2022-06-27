#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int countValidWords(string sentence)
    {
        for (int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i]!=' ')
        }
        return 0;
    }
};
/*
1 <= sentence.length <= 1000
sentence only contains lowercase English letters, digits, ' ', '-', '!', '.', and ','.
There will be at least 1 token.

"he bought 2 pencils, 3 erasers, and 1  pencil-sharpener." //6

*/
int main()
{
    int x = 'a';
    int y = ' ';
    int z = 'z';
    Solution sol;
    int ans = sol.countValidWords("abc efg");
}