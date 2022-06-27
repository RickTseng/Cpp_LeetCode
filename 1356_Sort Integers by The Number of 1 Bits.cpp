#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
bool cmp(int a, int b)
{
    int _a = a,_b = b;
    int idxA = 0, idxB = 0;
    while (a > 0)
    {
        if (a % 2 == 1)
        {
            idxA++;
        }
        a /= 2;
    }
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            idxB++;
        }     
        b /= 2;
    }
    if(idxA == idxB){
        return _a < _b;
    }
    return idxA < idxB;
}
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Solution sol;
    vector<int> ans = sol.sortByBits(arr);
    // vector<int> ans = sol.sortByBits(arr);
}