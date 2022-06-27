#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        long long p = 1;
        while (p<=INT32_MAX && p<=n)
        {
            if(p==n){
                return true;
            }
            p*=3;
        }
        return false;
    }
};
