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
    int maximumCandies(vector<int> &candies, long long k)
    {
        int left = 0, right = 10000000;
        while (left < right)
        {
            long long mid = (left + right + 1) / 2, count = 0;
            for (int i = 0; i < candies.size() && count < k; i++)
            {
                count += candies[i] / mid;
            }
                
            if (count >= k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
                
        }
        return left;
    }
};