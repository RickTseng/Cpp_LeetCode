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
    int minBitFlips(int start, int goal) {
        //vector<int> st(32,0),gt(32,0);
        int count = 0;
        while (start>0 || goal > 0)
        {
            if(start % 2 != goal % 2){
                count++;
            }
            start/=2;
            goal/=2;
        }
        return count;
    }
};