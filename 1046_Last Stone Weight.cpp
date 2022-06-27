#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;

// Runtime: 4 ms, faster than 37.20% of C++ online submissions for Last Stone Weight.
// Memory Usage: 7.6 MB, less than 32.87% of C++ online submissions for Last Stone Weight.


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s:stones) pq.push(s);
        while (pq.size()>1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x!=y){
                pq.push(x-y);
            }
        }
        return pq.empty()? 0: pq.top();
        
        
    }
};