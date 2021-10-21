#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        vector<int> fb(3, 0);
        fb[1] = 1;
        fb[2] = 1;
        if (n < 3)
        {
            return fb[n];
        }
        for (int i = 3; i <= n; i++)
        {
            fb.push_back(fb[i - 1] + fb[i - 2] + fb[i - 3]);
        }
        return fb[n];
    }
};
int main(){
    Solution sol;
    int ans = sol.tribonacci(37);
}

/*

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/