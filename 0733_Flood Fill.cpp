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
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if(image[sr][sc] == newColor){
            return image;
        }
        executeFill(image,sr,sc,image[sr][sc],newColor);
        return image;

    }
    void executeFill(vector<vector<int>> &image,int r,int c,int target,int newColor){
        if(r<0 || c<0 ||r>=image.size()||c>=image[r].size()){
            return;
        }
        if(image[r][c]!=target){
            return;
        }
        image[r][c] = newColor;
        executeFill(image,r-1,c,target,newColor);
        executeFill(image,r+1,c,target,newColor);
        executeFill(image,r,c-1,target,newColor);
        executeFill(image,r,c+1,target,newColor);
    }
};
int main(){
    vector<vector<int>> image = {
        {0,0,0},
        {0,1,1}
    };
    Solution sol;
    vector<vector<int>> ans = sol.floodFill(image,1,1,1);
}
/**
 * @brief Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Runtime: 19 ms, faster than 18.92% of C++ online submissions for Flood Fill.
Memory Usage: 14 MB, less than 52.04% of C++ online submissions for Flood Fill.
 */