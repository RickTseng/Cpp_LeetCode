#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1){
            return triangle[0][0];
        }
        int r = triangle.size()-1;
        
        while (r>0)
        {
            for(int c= 0;c+1<triangle[r].size();c++){
                triangle[r-1][c] += min(triangle[r][c],triangle[r][c+1]);
            }
            r--;
        }
        return triangle[0][0];
        
    }

};
/**
 * @brief Runtime: 4 ms, faster than 94.33% of C++ online submissions for Triangle.
 * Memory Usage: 8.6 MB, less than 59.16% of C++ online submissions for Triangle.
 * 
 */