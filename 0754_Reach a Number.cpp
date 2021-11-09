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
    int reachNumber(int target)
    {

        /*
         RickTseng108
         
         0 -> 1  (1 step)   1 % 2 = 1 odd  cover -1, 1
         1 -> 3  (2 step)   3 % 2 = 1 odd  cover -3,-1, 1, 3
         3 -> 6  (3 step)   6 % 2 = 0 even cover -6,-4,-2, 2, 4, 6
         6 -> 10 (4 step)  10 % 2 = 0 even cover -10,-8,-6,-4,-2, 2, 4, 6, 8, 10
        10 -> 15 (5 step)  15 % 2 = 1 odd  cover -15,-13,-11,-9,-7,-5,-3,-1, 1, 3, 5, 7, 9, 11, 13, 15
        15 -> 21 (6 step)  21 % 2 = 1 odd  cover -21,-19,-17,-15,-13,-11,-9,-7,-5,-3,-1, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21
         .
         .
         .
                
        */
        int tmp = 0;
        int cnt = 1;
        while (tmp < abs(target) || tmp % 2 != abs(target) % 2)
        {
            tmp += cnt;
            cnt++;
        }
        return cnt - 1;
    }
};
int main()
{
    Solution sol;
    int ans = sol.reachNumber(5);

}

/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reach a Number.
Memory Usage: 5.7 MB, less than 95.34% of C++ online submissions for Reach a Number.


Example 1:

Input: target = 2
Output: 3
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to -1 (2 steps).
On the 3rd move, we step from -1 to 2 (3 steps).
Example 2:

Input: target = 3
Output: 2
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to 3 (2 steps).
 

Constraints:

-10^9 <= target <= 10^9
target != 0

*/