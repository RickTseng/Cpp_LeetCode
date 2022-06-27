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
    bool isPalindrome(string s)
    {
        string tmp = "";
        for (auto c : s)
        {
            if (c > 64 && c < 91)
            {
                tmp += c + 32;
            }
            if (c > 96 && c < 123)
            {
                tmp += c;
            }
            if (c > 47 && c < 58)
            {
                tmp += c;
            }
        }
        int start = 0,end = tmp.size()-1;
        while (start<=end)
        {
            if(tmp[start]!=tmp[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
};
int main()
{
    int a = '0';
    int z = '9';
    cout << a << endl;
    cout << z << endl;
    Solution sol;
    bool ans = sol.isPalindrome("0P");
}