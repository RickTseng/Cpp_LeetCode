#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;
        if(n==0){
            return true;
        }
        if(flowerbed.size()<3){
            return false;
        }
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if(i==0 && flowerbed[i]==0&&flowerbed[i+1]==0){
                flowerbed[i] = 1;               
                count++;
                if(count>=n){
                    return true;
                }
                continue;
            }
            if (i >1 && flowerbed[i-1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i]==0)
            {
                flowerbed[i] = 1;
                count++;
                if(count>=n){
                    return true;
                }
                continue;
            }
            if(i + 2 == flowerbed.size()&& flowerbed[i] == 0&& flowerbed[i+1]==0){
                flowerbed[i + 1] = 1;
                count++;
                if(count>=n){
                    return true;
                }
                continue;
            }
        }
        return false;
        
    }
};
int main(){
    vector<int> flowerbed = {0,0,0,0,1};
    Solution sol;
    bool ans = sol.canPlaceFlowers(flowerbed,2);
}