#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long sumPens = 0;
        long long res = 0;
        int target = total;
        while(sumPens <= target)
        {
            res += total/cost2 + 1;
            sumPens += cost1;
            total -= cost1;
        }
        return res;
    }
};
int main(){
    Solution sol;
    long long ans = sol.waysToBuyPensPencils(20,10,5);
}
    
