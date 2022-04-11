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
    string minimizeResult(string expression)
    {
        //creat left pair and right pair
        vector<int> dbL, dbR;
        int _min = INT32_MAX;
        for (int i = 0; i < expression.size(); i++)
        {
            // fill left pair
            if (expression[i] == '+')
            {
                break;
            }
            dbL.push_back(expression[i] - '0');
        }
        for (int i = expression.size() - 1; i >= 0; i--)
        {
            // fill right pair
            if (expression[i] == '+')
            {
                break;
            }
            dbR.push_back(expression[i] - '0');
        }
        string res = "";
        for(int l = 0;l<dbL.size();l++){
            for(int r = 0;r<dbR.size();r++){
                string tmpS = "";
                int tmp = caculator(dbL,dbR,l-1,r-1,tmpS);
                if(tmp<_min){
                    _min = tmp;
                    res = tmpS;
                }
            }
        }
        return res;
    }
    int caculator(vector<int> dbL, vector<int> dbR, int leftIdx, int rightIdx,string &res)
    {
        // lPow is left multiplier 
        // rPow is right multiplier 
        // lMid is left multiplicand
        // rMid is right multiplicand
        int lPow = 0, rPow = 0, lMid = 0 , rMid = 0;
        string slPow = "", srPow = "" , slMid = "",srMid = "";
        for (int i = 0; i < dbL.size(); i++)
        {
            if (i <= leftIdx)
            {
                lPow += dbL[i];
                slPow += (dbL[i] + '0');
                if (i != leftIdx)
                {
                    lPow *= 10;
                }
            }
            else
            {
                lMid += dbL[i];
                slMid += (dbL[i] + '0');
                if (i != dbL.size() - 1)
                {
                    lMid *= 10;
                }
            }
        }
        int pR = 1,pMid = 1;
        for (int i = 0; i < dbR.size(); i++)
        {
            if (i <= rightIdx)
            {
                char tmp = dbR[i] + '0';
                srPow = tmp + srPow;
                rPow += dbR[i] * pR;
                pR *= 10;
            }
            else{
                char tmp = dbR[i] + '0';
                srMid = tmp + srMid;
                rMid += dbR[i] * pMid;
                pMid *=10;
            }
        }
        //Build string
        res = slPow + '(' + slMid + '+' + srMid + ')' + srPow ;

        //if leftIdx = -1 multiplier is 1 because the left for loop won't execute;
        if(lPow == 0){
            lPow = 1;
        }
        //if rightIdx = -1 multiplier is 1 because the right for loop won't execute;
        if(rPow == 0){
            rPow = 1;
        } 
        return lPow * (lMid + rMid) * rPow;
    }
};
int main()
{
    Solution sol;
    string ans = sol.minimizeResult("12+34");
}