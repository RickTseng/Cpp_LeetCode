#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        if(mass<asteroids[0])
        {
            return false;
        }
        long long _mux = mass +asteroids[0];
        for(int i = 1;i<asteroids.size();i++)
        {
            if(_mux<asteroids[i]){
                return false;
            }
            _mux+=asteroids[i];
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> asteroids(100000,99999);
    bool ans = sol.asteroidsDestroyed(100000,asteroids);
}
/*

Runtime: 361 ms, faster than 25.31% of C++ online submissions for Destroying Asteroids.
Memory Usage: 100.7 MB, less than 73.69% of C++ online submissions for Destroying Asteroids.

Constraints:

1 <= mass <= 10^5
1 <= asteroids.length <= 10^5
1 <= asteroids[i] <= 10^5

*/