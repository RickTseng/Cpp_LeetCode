#include <vector>
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
    bool isUgly(int n)
    {
        for (int i = 2; i < 6 && n; i++)
            while (n % i == 0)
                n /= i;
        return n == 1;
    }
};