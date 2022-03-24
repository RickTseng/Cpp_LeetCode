#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = right;
        while (res>left)
        {
            res = res & (res-1);
        }
        
        
        return res;
    }
};
int main(){
    Solution sol;
    int ans = sol.rangeBitwiseAnd(5,7);
}