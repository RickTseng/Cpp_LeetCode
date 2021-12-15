#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int countPoints(string rings)
    {
        vector<set<int>> db(10);
        int count = 0;
        for(int i =1;i<rings.size();i+=2){
            db[rings[i]-48].insert(rings[i-1]);
            
        }
        for(auto d:db){
            if(d.size()==3){
                count++;
            }
        }
        return count;
    }
};
int main(){
    Solution sol;
    cout<<sol.countPoints("B0B6G0R6R0R6G9")<<endl;
}
/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rings and Rods.
Memory Usage: 6.5 MB, less than 32.74% of C++ online submissions for Rings and Rods.

Input: rings = "B0B6G0R6R0R6G9"
Output: 1

Constraints:

rings.length == 2 * n
1 <= n <= 100
rings[i] where i is even is either 'R', 'G', or 'B' (0-indexed).
rings[i] where i is odd is a digit from '0' to '9' (0-indexed).

*/