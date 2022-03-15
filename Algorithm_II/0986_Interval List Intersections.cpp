#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> res;
        if (firstList.empty() || secondList.empty())
        {
            return res;
        }
        int i = 0, j = 0,k=max(firstList[0][0],secondList[0][0]);
        while(k<=1e9)
        {
            if(i>=firstList.size()||j>=secondList.size()){
                break;
            }
            int start = k,end = k;
            if ((k >= firstList[i][0] && k <= firstList[i][1]) && (k >= secondList[j][0] && k <= secondList[j][1]))
            {
                start = max(firstList[i][0],secondList[j][0]);
                end = min(firstList[i][1],secondList[j][1]);
                res.push_back({start,end});
                k = end+1;
            }         
            if(k>firstList[i][1]){
                i++;
            }
            if(k>secondList[j][1]){
                j++;
            }
            if(i>=firstList.size()||j>=secondList.size()){
                break;
            }
            k=max(firstList[i][0],secondList[j][0]);
        }
        return res;
    }
};
int main(){
    vector<vector<int>>firstList = {{0,2},{5,10},{13,23},{24,25}}, secondList = {{1,5},{8,12},{15,24},{25,26}};
    Solution sol;
    vector<vector<int>> ans = sol.intervalIntersection(firstList,secondList);
}