#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int tmpIncome = 0;
        double res = 0;
        for(int i = 0;i<brackets.size();i++)
        {
            if(income>=brackets[i][0])
            {
                res += (brackets[i][0] - tmpIncome) *  (brackets[i][1]);
                tmpIncome = brackets[i][0];
            }
            else
            {
                res += (income - tmpIncome) *  brackets[i][1];
                break;
            }
        }
        return res / 100;
    }
};
int main(){
    vector<vector<int>> tt = {{3,50},{7,10},{12,25}};
    Solution sol;
    double ans = sol.calculateTax(tt,10);
}