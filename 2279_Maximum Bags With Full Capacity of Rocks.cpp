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
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        
        for(int i = 0;i<capacity.size();i++){
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int count = 0;
        for(int i = 0;i<capacity.size();i++){
            if(capacity[i]==0){
                count++;
                continue;
            }
            if(additionalRocks - capacity[i]>0)
            {
                additionalRocks-=capacity[i];
                count++;
                continue;
            }
            if(additionalRocks - capacity[i] == 0)
            {
                count++;
                break;
            }
            if(additionalRocks - capacity[i] < 0)
            {
                break;
            }
        }
        return count;
    }
};

/**Constraints:

n == capacity.length == rocks.length
1 <= n <= 5 * 10^4
1 <= capacity[i] <= 10^9
0 <= rocks[i] <= capacity[i]
1 <= additionalRocks <= 10^9
*/