#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> findAllRecipes_V0(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        vector<string> res;
        vector<bool> record(recipes.size(), false);
        unordered_map<string, bool> mp;
        for (auto s : supplies)
        {
            mp[s] = true;
        }
        for (auto r : recipes)
        {
            mp[r] = false;
        }
        int count = 0;
        int r_count = 1;
        while (count != r_count)
        {
            r_count = count;
            for (int i = 0; i < ingredients.size(); i++)
            {
                if (record[i])
                {
                    continue;
                }
                int needs = ingredients[i].size();
                for (int j = 0; j < ingredients[i].size(); j++)
                {
                    if (mp[ingredients[i][j]])
                    {
                        needs--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (needs == 0)
                {
                    record[i] = true;
                    //supplies.push_back(recipes[i]);
                    mp[recipes[i]] = true;
                    res.push_back(recipes[i]);
                    count++;
                }
            }
            if (count == 0)
            {
                return res;
            }
        }
        return res;
    }
    
};
/*

Runtime: 1304 ms, faster than 22.30% of C++ online submissions for Find All Possible Recipes from Given Supplies.
Memory Usage: 94.1 MB, less than 77.82% of C++ online submissions for Find All Possible Recipes from Given Supplies.

*/