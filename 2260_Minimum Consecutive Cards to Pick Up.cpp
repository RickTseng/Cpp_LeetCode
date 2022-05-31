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
    int minimumCardPickup(vector<int>& cards) {
        //Record the latest card index value
        vector<int> dp(1000001,-1);
        int _min = 1000001;
        for(int idx = 0;idx<cards.size();idx++){
            //if the card value appear twice, calculate the length.
            if(dp[cards[idx]]!=-1)
            {
                _min = min(_min,idx - dp[cards[idx]] + 1);
            }
            dp[cards[idx]] = idx;
        }
        //if _min is 1000001 means there have't any one appear twice. 
        return _min == 1000001? -1:_min;
    }
};
int main(){
    vector<int> cards = {3,4,2,3,4,7};
    Solution sol;
    int ans = sol.minimumCardPickup(cards);
}