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
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int _min = 1e4 + 1;
        int id = -1;
        for(int idx = 0;idx<points.size();idx++){
            if(points[idx][0] == x && points[idx][1] == y){
                return idx;
            }
            if(points[idx][0] == x && abs(points[idx][1] - y)<_min)
            {
                id = idx;
                _min = abs(points[idx][1] - y);
            }
            if(points[idx][1] == y && abs(points[idx][0] - x)<_min)
            {
                id = idx;
                _min = abs(points[idx][0] - x);
            }
        }
        return id;
    }
};
int main(){
    Solution sol;
    int a =2e8;
    cout << a << endl;
}