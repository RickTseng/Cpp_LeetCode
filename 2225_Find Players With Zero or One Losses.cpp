#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<int> db(100001,0);
        vector<int> db1(100001,0);
        vector<vector<int>> res(2, vector<int>());
        for (auto matche : matches)
        {
            db1[matche[0]]=1;
            db1[matche[1]]=1;
            if(db[matche[1]]>1){
                continue;
            }
            db[matche[1]]++;
        }
        for(int i = 0;i<db1.size();i++){
            if(db1[i]==1){
                if(db[i]==0){
                    res[0].push_back(i);
                }
                if(db[i]==1){
                    res[1].push_back(i);
                }
            }
        }
        return res;
    }
};