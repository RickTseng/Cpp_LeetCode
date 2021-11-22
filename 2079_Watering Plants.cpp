#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int idx = 0;
        int step = 0;
        int _oCap = capacity;
        vector<bool> db(plants.size(),false);
        while (idx<plants.size())
        {
            if(!db[idx] && capacity>=plants[idx]){
                db[idx] = true;
                capacity-=plants[idx];
                idx++;
                step++;
            }
            else{
                step += idx * 2;
                capacity = _oCap;
            }
        }
        return step;
    }
};
int main(){
    Solution sol;
    vector<int> plants = {2,2,3,3};
    int ans = sol.wateringPlants(plants,5);
}
/*
Example 1:

Input: plants = [2,2,3,3], capacity = 5
Output: 14
Explanation: Start at the river with a full watering can:
- Walk to plant 0 (1 step) and water it. Watering can has 3 units of water.
- Walk to plant 1 (1 step) and water it. Watering can has 1 unit of water.
- Since you cannot completely water plant 2, walk back to the river to refill (2 steps).
- Walk to plant 2 (3 steps) and water it. Watering can has 2 units of water.
- Since you cannot completely water plant 3, walk back to the river to refill (3 steps).
- Walk to plant 3 (4 steps) and water it.
Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.
Example 2:

Input: plants = [1,1,1,4,2,3], capacity = 4
Output: 30
Explanation: Start at the river with a full watering can:
- Water plants 0, 1, and 2 (3 steps). Return to river (3 steps).
- Water plant 3 (4 steps). Return to river (4 steps).
- Water plant 4 (5 steps). Return to river (5 steps).
- Water plant 5 (6 steps).
Steps needed = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30.
Example 3:

Input: plants = [7,7,7,7,7,7,7], capacity = 8
Output: 49
Explanation: You have to refill before watering each plant.
Steps needed = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49.
 

Constraints:

n == plants.length
1 <= n <= 1000
1 <= plants[i] <= 10^6
max(plants[i]) <= capacity <= 10^9

Runtime: 8 ms, faster than 25.00% of C++ online submissions for Watering Plants.
Memory Usage: 8.4 MB, less than 50.00% of C++ online submissions for Watering Plants.

*/