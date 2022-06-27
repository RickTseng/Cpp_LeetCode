#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

// Runtime: 2 ms, faster than 60.85% of C++ online submissions for Self Dividing Numbers.
// Memory Usage: 6.4 MB, less than 87.60% of C++ online submissions for Self Dividing Numbers.



class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int>res;
        while (left<=right)
        {
            if(calculator(left)){
                res.push_back(left);
            }
            left++;
        }
        return res;
    }
    bool calculator(int target)
    {
        int _target = target;
        while (_target>0)
        {
            int d1 = _target%10;
            if(d1==0){
                return false;
            }
            if(target%d1!=0){
                return false;
            }
            _target/=10;
        }
        return true;
        
    }
};