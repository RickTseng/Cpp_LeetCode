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
    vector<int> constructRectangle(int area) {
        int W = 1;
        int L = area / W;
        int _minL = L;
        while (L>W)
        {
            if(area%W==0)
            {
                _minL = min(_minL,area/W);
            }
            W++;
            L = area/W;
        }
        return {_minL,area/_minL};
    }
};
int main(){
    Solution sol;
    vector<int> ans = sol.constructRectangle(37);
    cout << " " <<endl;
}