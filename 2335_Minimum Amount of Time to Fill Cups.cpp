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

// Runtime: 5 ms, faster than 100.00% of C++ online submissions for Minimum Amount of Time to Fill Cups.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Minimum Amount of Time to Fill Cups.

class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue<int> pq;
        for(auto n:amount){
            if(n>0) pq.push(n);
            
        }
        int a = 0,b = 0,count = 0;
        while(!pq.empty())
        {
            a = pq.top()-1;
            pq.pop();
            if(!pq.empty()){
                b = pq.top()-1;
                pq.pop();
                if(b>0){
                    pq.push(b);
                }
            }
            if(a > 0){
                pq.push(a);
            }
            count++;
        }
        return count;
    }
};
int main(){
    vector<int> amouut = {100,100,100};
    Solution sol;
    int ans =sol.fillCups(amouut);
}