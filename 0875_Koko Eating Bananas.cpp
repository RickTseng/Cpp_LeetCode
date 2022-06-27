#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int minEatingSpeed_b(vector<int> &piles, int h)
    {
        // Start at an eating speed of 1.
        int speed = 1;

        while (true)
        {
            // hourSpent stands for the total number of hours that
            // Koko has spent with the current eating speed.
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / speed)
            for (int pile : piles)
            {
                hourSpent += pile / speed + (pile % speed != 0);
                //int tmp = pile / speed + (pile % speed != 0);
                //int tmp1 = pile / speed;
                //int tmp2 = (pile % speed != 0);
                if (hourSpent > h)
                {
                    break;
                }
            }

            // Check if Koko can finish all the piles within h hours,
            // If so, return speed. Otherwise, let speed increment by
            // 1 and repeat the previous iteration.
            if (hourSpent <= h)
            {
                return speed;
            }
            else
            {
                speed += 1;
            }
        }
        return 0;
    }
    // binary search
    int minEatingSpeed(vector<int>& piles, int h) {     
        // Initalize the left and right boundaries 
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            // Get the middle index between left and right boundary indexes.
            // hourSpent stands for the total hour Koko spends.
            int middle = (left + right) / 2;
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / middle).
            for (int pile : piles) {
                hourSpent += pile / middle + (pile % middle != 0);
            }

            // Check if middle is a workable speed, and cut the search space by half.
            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the minimum workable eating speed.
        return right;
    }
};
int main(){
    vector<int> piles = {3,6,7,11};
    Solution sol;
    int ans = sol.minEatingSpeed(piles,8);
}