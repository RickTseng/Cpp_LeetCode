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
    int divisorSubstrings(int num, int k)
    {
        vector<int> tb;
        int target = num;
        long long div = 0;
        long long pow = 1;
        int count = 0;
        while (num > 0)
        {
            tb.insert(tb.begin(), num % 10);
            num /= 10;
        }
        for (int i = 0; i < k && i<tb.size(); i++)
        {
            div += tb[i];
            div *= 10;
            pow *= 10;
        }
        div/=10;
        pow/= 10;
        if (target % div == 0)
        {
            count++;
        }
        
        for (int i = k; i < tb.size(); i++)
        {
            div %= pow;
            div *= 10;
            div += tb[i];
            if (div != 0 && target % div == 0)
            {
                count++;
            }
        }
        return count;
    }
};
int main(){
    Solution sol;
    int ans = sol.divisorSubstrings(59005900,4);
}