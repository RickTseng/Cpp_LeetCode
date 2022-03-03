#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _min = 10001;
        int _max = 0;
        for(int i = 0;i<prices.size()-1;i++){
            if(prices[i]<_min && prices[i+1]>prices[i]){
                _min = prices[i];
                for(int j = i;j<prices.size();j++){
                    if(prices[j]>prices[i]&&prices[j]-prices[i]>_max){
                        _max = prices[j]-prices[i];
                    }
                }
            }
        }
        return _max;
    }
};