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
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        sort(special.begin(),special.end());
        long long _max = -1;
        if(special.front()-bottom>top-special.back())
        {
            _max = special.front()-bottom;
        }
        else{
            _max = top-special.back();
        }
        for(int i = 1;i<special.size();i++)
        {
            if(special[i]-special[i-1] - 1> _max){
                _max = special[i]-special[i-1] - 1;
            }
        }
        return _max;
    }
};