#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> pp(1001,0);
        int _max = 0;
        for(int i = 0;i<trips.size();i++){
            for(int j = trips[i][1];j<trips[i][2];j++){
                pp[j]+=trips[i][0];
                _max = max(_max,pp[j]);
            }
        }
        if(_max>capacity){
            return false;
        }
        return true;
    }
};
/*
Constraints:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 10^5

*/