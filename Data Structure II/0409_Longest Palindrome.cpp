#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> tb(26, 0), tbU(26, 0);
        int sum = 0;
        for (auto c : s)
        {
            if (c > 64 && c < 91)
            {
                tbU[c - 'A']++;
            }
            else
            {
                tb[c - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            sum += (tb[i] / 2) * 2;
            tb[i] %= 2;
        }
        for (int i = 0; i < 26; i++)
        {
            sum += (tbU[i] / 2) * 2;
            tbU[i] %= 2;
        }
        for (int i = 0; i < 26; i++)
        {
            if (tbU[i] == 1 || tb[i] == 1)
            {
                sum += 1;
                break;
            }
        }
        return sum;
    }
};
int main()
{
    int a = 'A';
    int z = 'Z';
    cout << a << endl;
    cout << z << endl;
}