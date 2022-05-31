#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
    {
        sort(tiles.begin(),tiles.end());
        int _max = 0;
        int count = 0;
        int idx = 0,jdx = 0;
        int i = 0,j = 1;
        for(i = 1;i<=carpetLen;i++){
            if(idx<tiles.size()&&i>tiles[idx][1]){
                idx++;
            }
            if(idx<tiles.size() && tiles[idx][0]<=i && i<=tiles[idx][1]){
                count+= (min(tiles[idx][1],carpetLen)-tiles[idx][0]+1);
                i=min(tiles[idx][1],carpetLen);
            }
        }
        for(;i<=1e9;i++,j++)
        {
            if(jdx<tiles.size() && j>tiles[jdx][1]){
                jdx++;
            }
            if(jdx>=tiles.size()){
                break;
            }
            if(j>=tiles[jdx][0] && j<=tiles[jdx][1]){
                count--;
            }
            if(idx<tiles.size()&& i> tiles[idx][1]){
                idx++;
            }
            if(idx>=tiles.size()){
                break;
            }
            if(idx<tiles.size()&& tiles[idx][0]<=i && i<=tiles[idx][1]){
                count++;
                _max = max(_max,count);
            }
        }
        return _max;
    }
};
int main(){
    vector<vector<int>> tiles = {{10,11},{1,5},{12,18},{20,25},{30,32}};
    Solution sol;
    int ans = sol.maximumWhiteTiles(tiles,10);
}