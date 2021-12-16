#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        vector<bool> rc(plants.size(), false);
        int idA = 0;
        int idB = plants.size() - 1;
        int tmpCA = capacityA;
        int tmpCB = capacityB;
        int stepA = 0;
        int stepB = 0;
        while (idA <= idB)
        {
            if (idA == idB)
            {
                cout << "GET" << endl;
                if(tmpCA < plants[idA] && tmpCB <plants[idB]){
                    stepA++;
                }
                break;
            }
            if (plants[idA] <= tmpCA)
            {
                tmpCA -= plants[idA];
                idA++;
            }
            else
            {
                rc[idA] = true;
                tmpCA = capacityA - plants[idA];
                stepA++;
                idA++;
            }

            if (plants[idB] <= tmpCB)
            {
                tmpCB -= plants[idB];
                idB--;
            }
            else
            {
                rc[idB] = true;
                tmpCB = capacityB - plants[idB];
                stepB++;
                idB--;
            }
        }
        return stepB + stepA;
    }
};
int main()
{
    vector<int> plants = {2, 2, 3, 3, 2, 1, 2, 1, 5, 2, 1, 2, 1, 5, 1, 1, 1, 5, 1, 5, 1, 5, 1, 1, 3, 4, 5};
    Solution sol;
    cout << sol.minimumRefill(plants, 5, 5) << endl;
}
/*

Constraints:

n == plants.length
1 <= n <= 10^5
1 <= plants[i] <= 10^6
max(plants[i]) <= capacityA, capacityB <= 10^9


Runtime: 124 ms, faster than 99.35% of C++ online submissions for Watering Plants II.
Memory Usage: 78.5 MB, less than 21.04% of C++ online submissions for Watering Plants II.

*/