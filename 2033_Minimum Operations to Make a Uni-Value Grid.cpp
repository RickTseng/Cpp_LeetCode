#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rlen = grid.size();
		int clen = grid[0].size();
		
		int _min = INT32_MAX;
        for (int i=0; i<rlen; i++)
            for (int j=0; j<clen; j++)
                _min = min(_min, grid[i][j]);
        
        vector<int>nums;
        for (int i=0; i<rlen; i++)
            for (int j=0; j<clen; j++)
            {
                if ((grid[i][j]-_min)%x!=0)
                    return -1;
                nums.push_back(grid[i][j]);
            }
        
        sort(nums.begin(), nums.end());
        int k = nums.size();
        int count = 0;
        for (auto t: nums)
        {
            count += abs(nums[(k-1)/2]-t)/x;
        }
        return count;
    }
};
int main(){

}