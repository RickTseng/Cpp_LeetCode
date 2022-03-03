#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }
        if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }
        vector<vector<int>> res = {{1}, {1, 1}};
        for (int i = 3; i <= numRows; i++)
        {
            vector<int> row(i, 1);
            for (int r = 1; r < res[i - 2].size(); r++)
            {
                row[r] = res[i - 2][r - 1] + res[i - 2][r];
            }
            res.push_back(row);
        }
        return res;
    }
};
int main(){
    cout<<"Hello world"<<endl;
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
}