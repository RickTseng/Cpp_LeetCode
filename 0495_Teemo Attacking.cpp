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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = duration;
        int start = timeSeries[0];
        int end = start + duration;
        int idx = 1;
        while(idx<timeSeries.size())
        {
            if(timeSeries[idx]<=end){
                count -= (end - timeSeries[idx]);
            }
            end = timeSeries[idx] + duration;
            count += duration;
            idx++;
        }
        return count;
    }
};
int main(){
    vector<int> t = {1,4,5};
    Solution sol;
    int ans = sol.findPoisonedDuration(t,4);
}