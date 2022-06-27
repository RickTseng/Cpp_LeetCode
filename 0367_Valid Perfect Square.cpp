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
    bool isPerfectSquare(int num) {
        long long p = 1;
        while (p * p <=INT32_MAX && p<=num)
        {

            if(p==num){
                return true;
            }
            p+=1;
        }
        return false;
    }
};